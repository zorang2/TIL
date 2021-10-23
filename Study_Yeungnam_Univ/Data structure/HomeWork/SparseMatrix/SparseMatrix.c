#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct { // �������� ������ ����ü
	int row; // ��
	int col; // ��
	float value; // ��
} term;

int Get_intData(); // ������ �Է¹޾� �������ִ� �Լ�
float Get_floatData(); // �Ǽ��� �Է¹޾� �������ִ� �Լ�

int InputSum(term *r, int total, int row, int col, float sum); // ����� �� ��� ����� �������ִ� �Լ�
void MatrixCpy(term *a, term *b, int i); // �� �������� �������ִ� �Լ�

int Get_MatrixFromFile();   // file���� �����͸� �о���� �Լ�
void Get_MatrixFromUser();  // �������� �����Է¹ޱ����� �Լ�
void Get_MatrixValue(term *Matrix, int MaxRow, int MaxCol, int MaxValue); // �������� �������ִ� �Լ�
void Get_TransposeMatrix(term *orgMatrix, term *transMatrix, int MaxRow, int MaxCol, int MaxValue); // ��ġ����� ����� �Լ�
void Get_ResultOfMultiplication(term *M_A, term *M_B, term *trans, // �� �������� �����ִ� �Լ�
								int MaxRowA, int MaxColA, int MaxValueA, int MaxRowB, int MaxColB, int MaxValueB);

void fprint_Matrix(term *Matrix, int MaxR, int MaxC, int MaxV); // ����� ������ִ� �Լ�
void fprint_SpaseMatrix(term *Matrix, int MaxV); // �������� ������ִ� �Լ�
void fprint_WholeResult(term *MatrixA, term *MatrixB, term *MatrixT, term *MatrixR, // ���� ��� ����� ������ִ� �Լ�
					   int MaxRA, int MaxCA, int MaxCB, int MaxA, int MaxB, int MaxR);

int main()
{
	int select, check;

	printf("========================================\n");
	printf("1. ���Ϸ� �о����    2. ���� �Է�      \n");
	printf("========================================\n");
	select = Get_intData();

	if(select == 1){
		check = Get_MatrixFromFile();
		if(check == 0) {printf("�߸��� �����Դϴ�.\n"); return 0;}
	}

	else if(select == 2){
		Get_MatrixFromUser();
	}

	return 0;
}

void Get_MatrixFromUser()
{
	////////////////////////////////////////////////////////////////////////////////////
	/*������ �� �� ����� �����Է¹޾ƿ��� ��� ȣ��Ǵ� �Լ��̴�. �� �Լ��� ���A,B�� /
	/��/�� �� ������ ������ �޾ƿ� �� �� ���Ҹ� �����Ѵ�.������ ������ B����� ��ġ���/
	/�� ��ȯ�� �� ������ �ϵ��� �Լ��� ȣ���Ѵ�.                                      */
	////////////////////////////////////////////////////////////////////////////////////

	int MRowA, MColA, MValueA; // ���A�� ��/��/���� ���� ������ ����
	int MRowB, MColB, MValueB; // ���B�� ��/��/���� ���� ������ ����
	term *Matrix_A; // ��� A
	term *Matrix_B; // ��� B
	term *Matrix_trans; // ���B�� ��ġ���

	/*���A�� ��/��/���� ������ �޾ƿ��� �κ�*/
	printf("���A�� �ప�� �Է��Ͻÿ� : ");
	MRowA = Get_intData();
	printf("���A�� ������ �Է��Ͻÿ� : ");
	MColA = Get_intData();
	printf("���A�� value ������ �Է��Ͻÿ� : ");
	MValueA = Get_intData();

	/*���A�� �������� �����ϴ� �κ�*/
	Matrix_A = (term *)malloc(MValueA * sizeof(term));
	Get_MatrixValue(Matrix_A, MRowA, MColA, MValueA);

	/*���B�� ��/��/���� ������ �޾ƿ��� �κ�*/
	MRowB = MColA; // ���B�� �ప�� ���A�� ������ ����
	printf("���B�� �ప�� %d �Դϴ�.\n", MRowB);
	printf("���B�� ������ �Է��Ͻÿ� : ");
	MColB = Get_intData();
	printf("���B�� value ������ �Է��Ͻÿ� : ");
	MValueB = Get_intData();

	/*���B�� �������� �����ϴ� �κ�*/
	Matrix_B = (term *)malloc(MValueB * sizeof(term));
	Get_MatrixValue(Matrix_B, MRowB, MColB, MValueB);

	/* ���B�� ��ġ����� �����ϴ� �κ�*/
	Matrix_trans = (term *)malloc(MValueB * sizeof(term)); 
	Get_TransposeMatrix(Matrix_B, Matrix_trans, MRowB, MColB, MValueB);

	/*��� A,B�� ��ġ����� �̿��Ͽ� �������� �κ�*/
	Get_ResultOfMultiplication(Matrix_A, Matrix_B, Matrix_trans, MRowA, MColA, MValueA, MRowB, MColB, MValueB);

	free(Matrix_A);
	free(Matrix_B);
	free(Matrix_trans);
}

int Get_MatrixFromFile()
{
	////////////////////////////////////////////////////////////////////////////////////
	/*�� �Լ��� ���Ϸ� ���� ����� �޾ƿ��� ��� ���Ǵ� �Լ��̴�.�Լ��� ȣ��Ǹ� ����/
	/array.dat�� ���� ù ������ ��/��/������ ������ �޾ƿͼ� �����Ѵ�.�� �� ������ ����/
	/������ ���ϻ󿡼� �� ���� ���忡 �ʿ��� �����͸� �޾ƿ´�. �̷��� ������� �� ��/
	/���� ��� �޾ƿ��� ��ġ����� �����ϰ� ������ �ϱ����� �Լ��� ȣ���� �ش�.       */
	////////////////////////////////////////////////////////////////////////////////////

	term *MatrixA, *MatrixB, *Matrix_trans;
	int MRowA, MRowB, MColA, MColB, MValA, MValB;
	int wcnt, mcnt, MV, i;
	char strbuf[10];
	FILE *in;

	in = fopen("array.dat", "r"); // ����� ����� ������ �����Ѵ�.
	wcnt = 0;

	while(wcnt < 2){
		// �ִ� �� �� ���� ��, ���Ҽ��� �޾ƿ��� �κ�
		if(fscanf(in, "%s", strbuf)){

			// ����� ������ �޾ƿ��� �κ�.
			if(wcnt == 0){ // A���
				MRowA = atoi(strbuf);
				if(MRowA < 1) { fclose(in); return 0; } // �� ������� 1���� ������ �ȵȴ�.
			}
			else{ // B���
				MRowB = atoi(strbuf);
				if(MRowB < 1) { fclose(in); return 0; }
			}
		}
		else { fclose(in); return 0; }

			// ����� ������� �޾ƿ��� �κ�.
		if(fscanf(in, "%s", strbuf)){
			if(wcnt == 0){ // A���
				MColA = atoi(strbuf);
				if(MColA < 1) { fclose(in); return 0; } // �� ������� 1���� ������ �ȵȴ�.
			}
			else{ // B���
				MColB = atoi(strbuf);
				if(MColB < 1) { fclose(in); return 0; }
			}
		}
		else { fclose(in); return 0; }

			// ������ ������ �޾ƿ��� �κ�
		if(fscanf(in, "%s", strbuf)){
			if(wcnt == 0){ // A���
				MValA = atoi(strbuf);
				if(MValA < 0) { fclose(in); return 0; } // ������ ���� �����̸� �ȵȴ�.
			}
			else{ // B���
				MValB = atoi(strbuf);
				if(MValB < 0) { fclose(in); return 0; }
			}
		} 
		else { fclose(in); return 0; }

		// end of get MaxData

		mcnt = 0;
		// ������ ������ �޾ƿ����Ƿ� �̸� �̿��Ͽ� ������ �迭�� ����� ����ش�.
		if(wcnt == 0) {
			MV = MValA;  // A��� ������ ���� ������ �޸𸮿� ����ش�.
			MatrixA = (term *)malloc((MValA) * sizeof(term));
		}
		else {
			MV = MValB; // B��� ������ ���� ������ �޸𸮿� ����ش�.
			MatrixB = (term *)malloc((MValB) * sizeof(term));
		}

		// �������� �����ϴ� �κ�.
		while(mcnt < MV){ // while���� ������ ������ŭ�� �����Ѵ�.

			if(fscanf(in, "%s", strbuf)){

				// ���� �޾ƿ��� �κ�. ���� ����� ����� �Ѿ�� �ȵǸ�, ������ ������ �ȵȴ�.
				if(wcnt == 0){ // get matrixA data
					MatrixA[mcnt].row = atoi(strbuf);
					if(MatrixA[mcnt].row >= MRowA) { fclose(in); return 0; }
					else if(MatrixA[mcnt].row < 0) { fclose(in); return 0; }
				}
				else{ // get matrixB data
					MatrixB[mcnt].row = atoi(strbuf);
					if(MatrixB[mcnt].row >= MRowB) { fclose(in); return 0; }
					else if(MatrixB[mcnt].row < 0) { fclose(in); return 0; }
				}
			}
			else { fclose(in); return 0; }

			// ���� �޾ƿ��� �κ�. ���� ����� ����� �Ѿ�� �ȵǸ�, ������ ������ �ȵȴ�.
			if(fscanf(in, "%s", strbuf)){
				if(wcnt == 0){ // get matrixA data
					MatrixA[mcnt].col = atoi(strbuf);
					if(MatrixA[mcnt].col >= MColA) { fclose(in); return 0; }
					else if(MatrixA[mcnt].col < 0) { fclose(in); return 0; }

					for(i = 0; i < mcnt; i++){ // ������ ���� �Ŀ��� ���ĵ� ���������� Ȯ���Ͽ� �ش�.
						if(MatrixA[i].row == MatrixA[mcnt].row){
							if(MatrixA[i].col >= MatrixA[mcnt].col) { fclose(in); return 0; }
						}
						else if(MatrixA[i].row > MatrixA[mcnt].row) { fclose(in); return 0; }
					}
				}
				else{ // get matrixB data
					MatrixB[mcnt].col = atoi(strbuf);
					if(MatrixB[mcnt].col >= MColB) { fclose(in); return 0; }
					else if(MatrixB[mcnt].col < 0) { fclose(in); return 0; }

					for(i = 0; i < mcnt; i++){
						if(MatrixB[i].row == MatrixB[mcnt].row){
							if(MatrixB[i].col >= MatrixB[mcnt].col) { fclose(in); return 0; }
						}
						else if(MatrixB[i].row > MatrixB[mcnt].row) { fclose(in); return 0; }
					}
				}
			}
			else { fclose(in); return 0; }

			// ���Ҹ� �޾ƿ��� �κ�. ���Ҵ� 0�̸� �������� ���� �����̹Ƿ� �������� �ʴ´�. 
			if(fscanf(in, "%s", strbuf)){
				if(wcnt == 0){ // get matrixA data
					MatrixA[mcnt].value = (float)atof(strbuf);
					if(MatrixA[mcnt].value == 0) { fclose(in); return 0; }
				}
				else{ // get matrixB data
					MatrixB[mcnt].value = (float)atof(strbuf);
					if(MatrixB[mcnt].value == 0) { fclose(in); return 0; }
				}
			}
			else { fclose(in); return 0; }

			mcnt++;

		} // end of MV while

		wcnt++;

	} // end of wcnt while

	fclose(in);

	/* ���B�� ��ġ����� �����ϴ� �κ�*/
	Matrix_trans = (term *)malloc(MValB * sizeof(term)); 
	Get_TransposeMatrix(MatrixB, Matrix_trans, MRowB, MColB, MValB);

	/*��� A,B�� ��ġ����� �̿��Ͽ� �������� �κ�*/
	Get_ResultOfMultiplication(MatrixA, MatrixB, Matrix_trans, MRowA, MColA, MValA, MRowB, MColB, MValB);

	free(MatrixA);
	free(MatrixB);
	free(Matrix_trans);

	return 1;
}

void Get_MatrixValue(term *Matrix, int MaxRow, int MaxCol, int MaxValue)
{
	////////////////////////////////////////////////////////////////////////////////////
	/*���� ����� �� �� ����� �޾� ���� �Լ�. �����Էµ� ��/�� ���� �̿��Ͽ� �̸� �Ѵ�/
	/���� �Էµ� ���� ����ó���� �ϰ� �ٽ� �Է��ϰ� �Ѵ�. �Էµ� value�� ���� ��ŭ ��/
	/for���� �����Ͽ� �� ���� �Է¹޾ƿ´�.                                           */
	////////////////////////////////////////////////////////////////////////////////////

	int j;
	int i = 0;

	while(i < MaxValue){ // MaxValue ��ŭ �� ����ȴ�.
		int tRow, tCol, flag = 1;
		printf("�Է��� Value�� �� ���� �Է��Ͻÿ� : ");
		tRow = Get_intData();
		printf("�Է��� Value�� �� ���� �Է��Ͻÿ� : ");
		tCol = Get_intData();
		
		if(tRow < MaxRow){ // �ִ� �ప�� Ȯ���Ѵ�.
			if(tCol < MaxCol){ // �ִ� ������ Ȯ���Ѵ�. 
				Matrix[i].col = tCol;
				Matrix[i].row = tRow;

				for(j = 0; j < i; j++){ // �����Ŀ� ��/������ ���ĵǼ� �������� Ȯ���Ѵ�.
					if(Matrix[j].row == Matrix[i].row){
						if(Matrix[j].col >= Matrix[i].col){
							printf("�߸� �Է��Ͽ����ϴ�. �ٽ� �Է��Ͻʽÿ�.\n");
							flag = 0;
						}
					}
					else if(Matrix[j].row > Matrix[i].row){
						printf("�߸� �Է��Ͽ����ϴ�. �ٽ� �Է��Ͻʽÿ�.\n");
						flag = 0;
					}
				}

				if(flag){
					printf("Value�� �Է��Ͻÿ� : ");
					Matrix[i].value = Get_floatData();
					i++; // �Է��� ���������� �̷���� ��� ���� ���� �Է¹ޱ� ���� i�� ������Ŵ.
				}
				else continue;
			}

			else printf("������ �߸� �Է��Ͽ����ϴ�.\n");
		} // end of if

		else printf("�ప�� �߸� �Է��Ͽ����ϴ�.\n");
	} // end of while

}

void Get_TransposeMatrix(term *orgMatrix, term *transMatrix, int MaxRow, int MaxCol, int MaxValue)
{
	//////////////////////////////////////////////////////////////////////////////////////////////
	/* ���B�� ��ġ����� �����ִ� �Լ�. row_terms�� �Էµ��ִ� �� �࿡ �ش��ϴ� value�� ������  /
	/ �����ϴ� �迭�̸�, starting_pos�� ��ġ����� �� �࿡ ���� �������� ���ĵǸ鼭 ����ɼ� �ֵ�/
	/ �� ������ ���� ��ġ��Ŀ��� ����� ��ġ�� �������ִ� �迭�̴�. ���� starting_pos�� row_term/
	/ �� �̿��Ͽ� �ʱⰪ�� �Է��ϰ�, �ش��ϴ� �࿡ �����Ͱ� ���� ���� ������Ű�鼭 ������ġ��/
	/ �������ش�. ��ġ����� row�� col�� �ٲپ� ������ ����� �ȴ�.                             */
	//////////////////////////////////////////////////////////////////////////////////////////////

	int *row_terms, *starting_pos;
	int i, j;
	int MRowT, MColT, MValueT; // ��ġ����� ��/��/���� ������ ������ ����

	row_terms = (int *)malloc(MaxCol * sizeof(int));
	starting_pos = (int *)malloc(MaxCol * sizeof(int));

	/*��ġ����� ���B�� ��,��,������ ������ ��,��,������ ������ �Ѵ�. */
	MRowT = MaxCol;
	MColT = MaxRow;
	MValueT = MaxValue;

	if(MaxValue > 0){ // ���Ұ� �����ϴ� ��� ����ȴ�.

		for(i = 0; i < MaxCol; i++) row_terms[i] = 0; // row_terms �ʱ�ȭ
		for(i = 0; i < MaxValue; i++) row_terms[orgMatrix[i].col]++; // row_terms�� �� �� ������ ���� ����.

		starting_pos[0] = 0;  // ù ���� ��ġ�� 0���� �ʱ�ȭ

		for(i = 1; i < MaxCol; i++) // row_terms�� �̿��Ͽ� �� ���� ���� ��ġ ����.
			starting_pos[i] = starting_pos[i-1] + row_terms[i-1];

		for(i = 0; i < MaxValue; i++){ // ��ġ��Ŀ� ���B�� ���Ҽ� ��ŭ �� ���� �����Ѵ�.
			j = starting_pos[orgMatrix[i].col]++; // ������ġ�� j�� �����ϰ� starting_pos�� ������Ŵ.
			transMatrix[j].row = orgMatrix[i].col; //��ġ����� �࿡ ���B�� ������ ����.
			transMatrix[j].col = orgMatrix[i].row; //��ġ����� ���� ���B�� �ప�� ����.
			transMatrix[j].value = orgMatrix[i].value; //���� ����.
		} // end of for

	} // end of if

	free(row_terms);
	free(starting_pos);
}

void Get_ResultOfMultiplication(term *M_A, term *M_B, term *trans,
								int MaxRowA, int MaxColA, int MaxValueA, int MaxRowB, int MaxColB, int MaxValueB)
{
	//////////////////////////////////////////////////////////////////////////////////////////////////
	/*���A�� ���B�� ��ġ����� �̿��Ͽ� ���� �� �� ����� Result�� �������ִ� �Լ�. ����� ������  /
	/ ù ����� ������� �ι�° ����� �� ������ �̵��ϸ鼭 ������ �����ϰ� �ǹǷ� ��ġ����� �̿��� /
	/ �� ������ �ϱⰡ ������ ����. �� �Լ������� ��ġ����� �Ķ���ͷ� �޾ƿ� ������ �̿��ϸ�, ���� /
	/ ���� �� ������ �����ϴ� ��ġ����� �ش��ϴ� ���� �������� ���� �� ���������� ���ؼ� ����� ����/
	/ �ϰ� �ȴ�. ������ �����ϴ� ���A�� �ప�� ���� row�� �����ϸ�, �ش� ���� �����Ļ󿡼� ���۵� /
	/ �� ��ġ�� ���� row_begin���� �����Ѵ�. ��ġ����� ����� ����ǰ��ִ� ���� ���� col�� �����ϸ�,/
	/ �ش� �࿡���� ���� j�� ������ �ش�. ���A�� ��ġ����� ������ ������ ���μ� ���Ұ� �����ϸ�, /
	/ ������ �Ͽ� sum�� �����ش�. ��꿡 �̿�Ǵ� ����� �����ķ� ����Ǿ� �����Ƿ� ���A,B�� ���� /
	/ ���� ��ŭ�� �� for���� �����ϸ� �ȴ�. ����Ǵ� ��� Result�� ������������ �ʱ⿡�� ���Ұ� �� /
	/ �� ���� �ϴ��� �� �� �����Ƿ� ���A,B�� ���Ҽ��� ���� ��ŭ �޸𸮸� ����ְ� ���ڸ��� �Ǵ� /
	/ ���� ���� ũ���� 2�踸ŭ �޸𸮸� �÷��ִ� ������ �������� ����ش�.                      */
	//////////////////////////////////////////////////////////////////////////////////////////////////

	int i, j, total, row_Begin, row, col;
	/*i�� ���A�� ���� ���� ���� 
	  j�� ��ġ����� ���� ���� ����
	  total�� Result����� ������ ������ ���� ����
	  row_begin�� ������ ������ �ش� ���� ������ ���� ��ġ�� ������ ����
	  row�� ���� ������ ����ǰ� �ִ� ����A ���� ���� ��Ÿ�� ����
	  col�� ���� ������ ����ǰ� �ִ� ��ġ��� ���� ���� ��Ÿ�� ����*/

	int MaxResult; // Result ����� ũ�⸦ ��Ÿ�� ���� 
	float sum; // �� ������ ������� ���ؼ� ������ ����
	term *Result, *temp;

	total = 0;
	row_Begin = 0; // ���� ���� ��ġ
	row = M_A[0].row; // ���� ���� ����
	sum = 0;
	MaxResult = MaxValueA + MaxValueB; // �ʱ� �������� ũ��

	if(MaxColA != MaxRowB){ // ���A�� ���� ���B�� ���� �ٸ��� ����ó��
		printf("�߸��� ����Դϴ�.\n");
		return;
	}

	Result = (term *)malloc((MaxResult) * sizeof(term));

	for(i = 0; i < MaxValueA;){ // ���A�� ���� �� ��ŭ ����
		col = trans[0].row; // ��ġ����� ����� ������ �� ����.

		for(j = 0; j <= MaxValueB;){ 
			// ��ġ����� ���Ҽ� + 1 ��ŭ ����. �����Ŀ� �����ϴ� ��츦 ���� �ѹ� �� for���� ���� ����.

			if(M_A[i].row != row){ // ��� �� ���� �ƴѰ��.
				if(sum != 0){ // �������� ������ ���� �ִٸ� �̸� �����Ѵ�.
					if(total < MaxResult){ // �������� ������ �����ִ� ���
						total = InputSum(Result, total, row, col, sum); // ������ ����� �����Ŀ� ����
						sum = 0; // �ʱ�ȭ
					}
					else { // ��� ��Ŀ� ������ ������ ��� �޸𸮸� �ι�� ����� �� ����.
						temp = (term *)malloc(MaxResult * sizeof(term));
						MatrixCpy(temp, Result, MaxResult);
						free(Result);
						Result = (term *)malloc((MaxResult*2) * sizeof(term));
						MatrixCpy(Result, temp, MaxResult);
						free(temp);

						MaxResult *= 2;
						total = InputSum(Result, total, row, col, sum);
						sum = 0;
						
					}// dynamic memory
				} // end of storesum

				i = row_Begin; // ���A�� ��� ���� ��ġ�� �ٽ� �����
				for(;trans[j].row == col; j++); // ��ġ����� ���� ������ �̵�
				col = trans[j].row; // ��ġ����� ��� ������ġ �ٽ� ����.
			} // end of if

			else if(trans[j].row != col){ // ���� ��ġ����� ���� �ƴѰ��.
				if(sum != 0){ // ������� �����Ѵٸ� �����Ŀ� ��������.
					if(total < MaxResult){
						total = InputSum(Result, total, row, col, sum);
						sum = 0;
					}
					else { // �������� ������ ������ ��� �ι�� �÷��ְ� ����� ��������.
						temp = (term *)malloc(MaxResult * sizeof(term));
						MatrixCpy(temp, Result, MaxResult);
						free(Result);
						Result = (term *)malloc((MaxResult*2) * sizeof(term));
						MatrixCpy(Result, temp, MaxResult);
						free(temp);

						MaxResult *= 2;
						total = InputSum(Result, total, row, col, sum);
						sum = 0;
					}// dynamic memory
				} // end of storesum
				i = row_Begin; // ���A�� ��� ���� ��ġ ����.
				col = trans[j].row; // ��ġ����� ��� ���� ��ġ �ٽ� ����.
			} // end of else if

			else{ // ���� ���� �����Ѵٸ� ����� �����ϴ� �κ�.
				if(M_A[i].col < trans[j].col) { i++; } // ��ġ����� ������ ���A�� ���� ���� ��� ���A�� i���� ������Ŵ.

				else if(M_A[i].col == trans[j].col){ // ���A�� ���� ��ġ����� ���� �����ϴٸ� ��� ����.
					sum += (M_A[i].value * trans[j].value); i++; j++;
				}
			
				else { j++; } // ���A�� ������ ū���� ��ġ����� j���� ������Ŵ.
			} // end of else

		} // end of B for

		for(; M_A[i].row == row; i++); // ���� ����� ���� ���A�� ���� ������ �̵�.
		row_Begin = i; // ����� ���� ������ ���� ������ġ�� �ٽ� ����.
		row = M_A[i].row; // ����� �ప�� �ٽ� ����.

	} // end of A for

	fprint_WholeResult(M_A, M_B, trans, Result, MaxRowA, MaxColA, MaxColB, MaxValueA, MaxValueB, total);
			// ��� ����� ȭ�鿡 ���.
	free(Result);
}

int InputSum(term *r, int total, int row, int col, float sum)
{
	////////////////////////////////////////////////////////////
	/*���A �� ��ġ����� �̿��Ͽ� ������ ������ ����� Result /
	/ ��Ŀ� �������ִ� �Լ�.                                 */
	////////////////////////////////////////////////////////////

	r[total].row = row;
	r[total].col = col;
	r[total].value = sum;
	total++; // Result����� ���Ҽ��� ������Ŵ.

	return total;
}

void MatrixCpy(term *a, term *b, int i)
{
	///////////////////////////////////////////////
	/*������a�� ������b�� �����ϴ� �Լ�.     */
	///////////////////////////////////////////////

	int k;
	for(k = 0; k < i; k++){
		a[k].col = b[k].col;
		a[k].row = b[k].row;
		a[k].value = b[k].value;
	}
}

void fprint_WholeResult(term *MatrixA, term *MatrixB, term *MatrixT, term *MatrixR,
					   int MaxRA, int MaxCA, int MaxCB, int MaxA, int MaxB, int MaxR)
{
	///////////////////////////////////////////////////////////////////////////////
	/*���α׷��� ���� ��� ������ �� �������� ����� ����� ����ϴ� �Լ�.   */
	///////////////////////////////////////////////////////////////////////////////

	FILE *out;
	

	/*�����ĵ��� ���*/
	out = fopen("a.out", "w"); // ��� file�� �̸��� a.out�̴�.
	fprintf(out, "\n�Է��� ���A�� ������ ǥ�� \n");
	fclose(out);
	fprint_SpaseMatrix(MatrixA, MaxA);
	out = fopen("a.out", "a");
	fprintf(out, "�Է��� ���B�� ������ ǥ�� \n");
	fclose(out);
	fprint_SpaseMatrix(MatrixB, MaxB);
	out = fopen("a.out", "a");
	fprintf(out, "�Է��� ���B�� ��ġ��� ǥ�� \n");
	fclose(out);
	fprint_SpaseMatrix(MatrixT, MaxB);
	out = fopen("a.out", "a");
	fprintf(out, "��� �������� ������ ǥ�� \n");
	fclose(out);
	fprint_SpaseMatrix(MatrixR, MaxR);

	/*���A, ���B, �������� ���*/
	out = fopen("a.out", "a");
	fprintf(out, "�Է��� �� ��� : \n");
	fclose(out);
	fprint_Matrix(MatrixA, MaxRA, MaxCA, MaxA);
	fprint_Matrix(MatrixB, MaxCA, MaxCB, MaxB);
	out = fopen("a.out", "a");
	fprintf(out, "��� ��� ��� : \n");
	fclose(out);
	fprint_Matrix(MatrixR, MaxRA, MaxCB, MaxR);
	printf("���File a.out�� �����Ǿ����ϴ�.\n");
}

void fprint_Matrix(term *Matrix, int MaxR, int MaxC, int MaxV)
{
	//////////////////////////////////////////////////////////
	/*����� ��ü ����� ����ϴ� �Լ�. ������ �� ���Ұ� /
	/ ���� ���� 0�� ����Ͽ� �ش�.                        */
	//////////////////////////////////////////////////////////

	int i, j, k;
	float t;

	FILE *out;
	out = fopen("a.out", "a");

	t = 0; // �����Ļ� ���Ұ� ���� ��� ��µ� ��.
	k = 0;
	
	for(i = 0; i < MaxR; i++){ // �ִ� �� ��ŭ ����
		for(j = 0; j < MaxC; j++){ // �ִ� �� ��ŭ ����
			if(k < MaxV){ // �����Ļ� ���� ���Ұ� �ִ� ��� 
				// ���� ��/���� ���Ұ� �ִٸ� �� ���� ����Ͽ� �ش�.
				if(Matrix[k].row == i && Matrix[k].col == j){ fprintf(out, "%f  ", Matrix[k].value); k++; }
				else fprintf(out, "%f  ", t); // ���Ұ� ���� ��� 0�� ���.
			}
			else fprintf(out, "%f  ", t); // ���̻� �����Ŀ� ���Ұ� ���ٸ� ���� �κп��� 0�� ���.
		}
		fprintf(out, "\n");
	}
	fprintf(out, "\n");

	fclose(out);
}

void fprint_SpaseMatrix(term *Matrix, int MaxV)
{
	//////////////////////////////////////////////////////////
	/*�������� ����Ͽ� �ִ� �Լ�.                        */
	//////////////////////////////////////////////////////////
	int i;
	FILE *out;
	out = fopen("a.out", "a");

	fprintf(out, "row    col    value\n");
	fprintf(out, "===================\n");
	for(i = 0; i < MaxV; i++)
		fprintf(out, "%d     %d     %f   \n", Matrix[i].row, Matrix[i].col, Matrix[i].value);

	fprintf(out, "\n");
	fclose(out);
}

int Get_intData()
{
	/////////////////////////////////////////////////////////////////////
	/*�������� �Է¹޾ƾ� �ϴ� ��� �������� �Է��� �̷�� ���� �� �˻� /
	/ �� �� atoi�Լ��� �̿��Ͽ� �ش� �������� ��ȭ�Ͽ� �ִ� ������ �ϴ� /
	/ �Լ�. ���� �Է��� string���� �޾ƿ´�.                           */
	/////////////////////////////////////////////////////////////////////

	char temp[10];  // �Է� ���� ���ڿ��� ������ �迭
	int flag;
	flag = 1;

	while(flag){
		int len, i;
		scanf("%s", temp);
		len = strlen(temp); // �Է¹��� ���ڿ��� ���̸� �˾ƿ�.
		flag = 0;

		for(i = 0; i < len;){ // �Է¹��� �� ���ڵ��� ������ �ش��ϴ��� �˻�.
			if(temp[i] < 48 || temp[i] > 57){ // 0~9�� �ش����� �ʴ� ���� �ٽ� �Է¹���.
				printf("�߸� �Է��Ͽ����ϴ�. �ٽ� �Է��Ͻʽÿ�.\n");
				flag = 1; break;
			} // end of if
			else i++;
		} // end of for
	} // end of while

	return atoi(temp); // �������� �Է��� �̷�����ٸ� atoi�Լ��� �̿��Ͽ� ���Ͻ�Ŵ.
}

float Get_floatData()
{
	////////////////////////////////////////////////////////////////////////////////////
	/*�Ǽ����� �ش�Ǵ� ���� �޾ƿ;� �ϴ� ��� �������� �Է��� �̷���������� Ȯ���Ͽ�/
	/ atof�Լ��� �Ǽ����� �������ִ� �Լ�.                                            */
	////////////////////////////////////////////////////////////////////////////////////

	char temp[10];
	int flag;
	flag = 1;

	while(flag){
		int len, i, dotcnt, mnscnt; // dotcnt�� '.'�� �ùٸ� ��ġ�� �ϳ��� ���� ���� �����ϴ� ����.
		                            // mnscnt�� '-'��ȣ�� �ùٸ��� ������������ Ȯ���ϴ� ����.
		scanf("%s", temp);
		len = strlen(temp);
		flag = dotcnt = mnscnt = 0;

		for(i = 0; i < len;){
			if((len == 1) && (temp[0] < 48 || temp[0] > 57)){ // �Ѱ��� ���ڸ� �Է��� ���� 0~9�� �ش��ϴ� ��츸 
				                                              // �ùٸ� �Է����� �����Ѵ�.
				printf("�߸� �Է��Ͽ����ϴ�. �ٽ� �Է��Ͻʽÿ�.\n");
				flag = 1; break;
			}

			else{ // �Ѱ��� �ʰ��ϴ� ���ڰ� �Էµ� ���.
				if(temp[i] < 48 || temp[i] > 57){ // 0~9�� �ش���� �ʴ� ���ڰ� �����ϴ� ���.
					if(i == 0 && temp[i] == '-'){ mnscnt++; i++; } // ù ���ڷμ��� '-'������ 0~9�� �����ϰ� �� �� �ִ�.

					else if(i != 0 && temp[i] == '.' && dotcnt == 0) { // ù ���ڰ� �ƴ� ���� '.'�� �� �� �ִ�.
						if(mnscnt > 0 && i == 1){ // '.'�� '-'�� ������ ���� �ι�° �ڸ��� �� �� ����.
							printf("�߸� �Է��Ͽ����ϴ�. �ٽ� �Է��Ͻʽÿ�.\n");
							flag = 1; break;
						}
						else{ dotcnt++; i++; } // '.'�� �ϳ��� �� �� �����Ƿ� �̸� ǥ�����ش�.
					}

					else{
						printf("�߸� �Է��Ͽ����ϴ�. �ٽ� �Է��Ͻʽÿ�.\n");
						flag = 1; break;
					}
				} // end of if

				else i++;
			} // end of else
		} // end of for
	} // end of while

	return (float)atof(temp); // �������� �Է��� �̷���� ���� atof�� �̿��Ͽ� �������ش�.
}


///////////////////////////////////////////////////
/*�ð�,�������⵵ ��� �� �ҽ��ڵ� ����.         */
///////////////////////////////////////////////////
/*

1. �������⵵�� ���
 �̹� ���α׷������� 4���� �����迭�� ���Ǿ���. A���, B��� �� ��ġ���, A,B�� ���� ����� �����ϰ� �� ����ü �迭�̸�, 
 ���� ��ġ����� B��İ� ������ ������� �����ִ�.�׿� ������������ Big-Oh notation���� ���� ���⵵�� ǥ���ϴ� ��� ����� 
 ���Ǿ����Ƿ� �����ص� ����� ����. 4���� �����迭 �� ��ġ����� B��İ� ����� �׻� �����ϹǷ� B����� ����� n2�� 
 �Ҷ� 2*(n2)���Ǿ� Big-Oh�� ǥ���ϴ� ��� ���⵵�� ������ ����. ���� A��� ����� n1, �����Ļ���� n3�̶� �Ҷ� 
 ���α׷��� ���� ���⵵�� Big-Oh�� ǥ���ϸ� O(n1+n2+n3)�� �ȴ�.

2. �ð����⵵�� ���
 �������� ���� ���α׷��� ������ �����ϴ� �κ��� �ٽ��̸�, �� �κ��� �ð� ���⵵�� ���α׷��� ������ �¿��ϰԵȴ�. �����
 ������ �����Ǵ� �Լ��� �� 4���̸�, �� �� A����� �� ����� B��ġ����� �ప���� ���Ͽ� ���� ����� �����Ŀ� �����ϴ� �Լ���
 InputSum�� ���� ����ð��� ����Ǿ� �ð����⵵�� ������ ������, �������� �޸� Ȯ���� ���� �������� ���Ǵ� ������ ��ȯ
 �Լ��� MatrixCpy�� ����ð��� ����ǹǷ� �ð����⵵ ��꿡�� �����Ѵ�. ���� ���� ��ġ����� ����� Get_TransposeMatrix�� ������
 �����ϴ� ResultOfMultiplication�̴�. ��ġ����� ����� �۾��� �ѹ��� �ϸ� �ǹǷ� �̸� ���� ����Ѵ�. �켱 ��ġ����� ����ϴ�
 �Լ������� 4���� for���� �����ϸ�, �̴� ���� MaxCol, MaxValue, MaxCol, MaxValue ��ŭ ����ȴ�. ���⼭ MaxCol�� B����� ��������
 �� ��Ÿ���� ���̸� MaxValue�� ������ ���� ��Ÿ����. �ݺ��� ���� ������ ����ð��� ����ǹǷ� �ð����⵵�� ������ ����, for����
 2*MaxCol + 2*MaxValue ��ŭ ����ǹǷ� Big-Oh notation���� ǥ���ϸ� O(MaxCol + MaxValue)�� �ȴ�. �������� ���� �Լ��� �м��ϸ�,
 ���⿡�� for���� �������� �� ������, ���� for���� MaxValueA(A��� ���Ҽ�), ���� for���� MaxValueB(B��� ���Ҽ�)�� ���� ����
 ���� �Ѵ�. ������ ���� for���� i���� �缳�� �Ǵ� ��찡 �����Ƿ� �̸� ����ؾ� �ϴµ�, K�� A����� ���� �࿡ �ִ� ���� �� �����
 i�� A����� ���� ������ �̵��ϱ� ���� ���ƾ� k�� ��ŭ ������ �� �ִ�. �� ��� i�� �缳���ϴ� ���ÿ� col�� ���� ���� ������ �ȴ�.
 ���� �� �缳���� ���ƾ� MaxColB(B����� ���� ��)���̰�, i�� �ִ� �� �������� MaxColB*k�� �ȴ�. �׿����� ���� for���� �ִ�
 �ݺ����� MaxColB+MaxColB*k+MaxValueB�̴�. ���� ���� �������� ���� ���� fora���� �ҿ�Ǵ� �ð��� O(MaxColB*k+MaxValueB)�̸�, ����
 ������ �����ϴ� �� �ɸ��� �ð��� O(k)�� �ȴ�. �׷��Ƿ� ���� for���� �ѹ� �ݺ��ϴ� �� �ɸ��� �ð��� O(MaxColB*k+MaxValueB)�̴�.
 �װ�� ��ü �ҿ�ð��� O(sigma(MaxColB*k+MaxValueB))=O(MaxColB*MaxValueA + MaxRowA*MaxValueB) �̴�. �� ����� ���� �־��� �ð�
 ���⵵�� ���غ���, MaxValueA<=MaxRowA*MaxColA, MaxValueB<=MaxRowB*MaxColA �̹Ƿ�, �־��� ��� O(MaxRowA*MaxColA*MaxColB)�� �ð�
 ���⵵�� ���Եȴ�.

3. ���� �Լ��� ����
(1) void Get_MatrixFromUser();
	������ �� �� ����� �����Է¹޾ƿ��� ��� ȣ��Ǵ� �Լ��̴�. �� �Լ��� ���A,B�� 
	��/�� �� ������ ������ �޾ƿ� �� �� ���Ҹ� �����Ѵ�.������ ������ B����� ��ġ���
	�� ��ȯ�� �� ������ �ϵ��� �Լ��� ȣ���Ѵ�.                                      

(2) int Get_MatrixFromFile(); 
	�� �Լ��� ���Ϸ� ���� ����� �޾ƿ��� ��� ���Ǵ� �Լ��̴�.�Լ��� ȣ��Ǹ� ����
	array.dat�� ���� ù ������ ��/��/������ ������ �޾ƿͼ� �����Ѵ�.�� �� ������ ����
	������ ���ϻ󿡼� �� ���� ���忡 �ʿ��� �����͸� �޾ƿ´�. �̷��� ������� �� ��
	���� ��� �޾ƿ��� ��ġ����� �����ϰ� ������ �ϱ����� �Լ��� ȣ���� �ش�.       

(3) void Get_MatrixValue(term *Matrix, int MaxRow, int MaxCol, int MaxValue);
	���� ����� �� �� ����� �޾� ���� �Լ�. �����Էµ� ��/�� ���� �̿��Ͽ� �̸� �Ѵ�
	���� �Էµ� ���� ����ó���� �ϰ� �ٽ� �Է��ϰ� �Ѵ�. �Էµ� value�� ���� ��ŭ ��
	for���� �����Ͽ� �� ���� �Է¹޾ƿ´�.                                           

(4) void Get_TransposeMatrix(term *orgMatrix, term *transMatrix, int MaxRow, int MaxCol, int MaxValue);
	���B�� ��ġ����� �����ִ� �Լ�. row_terms�� �Էµ��ִ� �� �࿡ �ش��ϴ� value�� ������ 
	�����ϴ� �迭�̸�, starting_pos�� ��ġ����� �� �࿡ ���� �������� ���ĵǸ鼭 ����ɼ� �ֵ�
	�� ������ ���� ��ġ��Ŀ��� ����� ��ġ�� �������ִ� �迭�̴�. ���� starting_pos�� row_term
	�� �̿��Ͽ� �ʱⰪ�� �Է��ϰ�, �ش��ϴ� �࿡ �����Ͱ� ���� ���� ������Ű�鼭 ������ġ��
	�������ش�. ��ġ����� row�� col�� �ٲپ� ������ ����� �ȴ�.                             

(5) void Get_ResultOfMultiplication(term *M_A, term *M_B, term *trans, int MaxRowA, int MaxColA, int MaxValueA, int MaxRowB, int MaxColB, int MaxValueB);
	���A�� ���B�� ��ġ����� �̿��Ͽ� ���� �� �� ����� Result�� �������ִ� �Լ�. ����� ������  
	ù ����� ������� �ι�° ����� �� ������ �̵��ϸ鼭 ������ �����ϰ� �ǹǷ� ��ġ����� �̿��� 
	�� ������ �ϱⰡ ������ ����. �� �Լ������� ��ġ����� �Ķ���ͷ� �޾ƿ� ������ �̿��ϸ�, ���� 
	���� �� ������ �����ϴ� ��ġ����� �ش��ϴ� ���� �������� ���� �� ���������� ���ؼ� ����� ����
	�ϰ� �ȴ�. ������ �����ϴ� ���A�� �ప�� ���� row�� �����ϸ�, �ش� ���� �����Ļ󿡼� ���۵� 
	�� ��ġ�� ���� row_begin���� �����Ѵ�. ��ġ����� ����� ����ǰ��ִ� ���� ���� col�� �����ϸ�,
	�ش� �࿡���� ���� j�� ������ �ش�. ���A�� ��ġ����� ������ ������ ���μ� ���Ұ� �����ϸ�, 
	������ �Ͽ� sum�� �����ش�. ��꿡 �̿�Ǵ� ����� �����ķ� ����Ǿ� �����Ƿ� ���A,B�� ���� 
	���� ��ŭ�� �� for���� �����ϸ� �ȴ�. ����Ǵ� ��� Result�� ������������ �ʱ⿡�� ���Ұ� �� 
	�� ���� �ϴ��� �� �� �����Ƿ� ���A,B�� ���Ҽ��� ���� ��ŭ �޸𸮸� ����ְ� ���ڸ��� �Ǵ�
	���� ���� ũ���� 2�踸ŭ �޸𸮸� �÷��ִ� ������ �������� ����ش�.                      

(6) int InputSum(term *r, int total, int row, int col, float sum);
	���A �� ��ġ����� �̿��Ͽ� ������ ������ ����� Result 
	��Ŀ� �������ִ� �Լ�.                                 

(7) void MatrixCpy(term *a, term *b, int i);
	������a�� ������b�� �����ϴ� �Լ�.     

(8) void fprint_Matrix(term *Matrix, int MaxR, int MaxC, int MaxV);
	����� ��ü ����� ����ϴ� �Լ�. ������ �� ���Ұ�
	���� ���� 0�� ����Ͽ� �ش�.                        

(9) void fprint_SpaseMatrix(term *Matrix, int MaxV);
	�������� ����Ͽ� �ִ� �Լ�.                        

(10)void fprint_WholeResult(term *MatrixA, term *MatrixB, term *MatrixT, term *MatrixR, int MaxRA, int MaxCA, int MaxCB, int MaxA, int MaxB, int MaxR);
	���α׷��� ���� ��� ������ �� �������� ����� ����� ����ϴ� �Լ�.   

(11)int Get_intData();
	�������� �Է¹޾ƾ� �ϴ� ��� �������� �Է��� �̷�� ���� �� �˻� 
	�� �� atoi�Լ��� �̿��Ͽ� �ش� �������� ��ȭ�Ͽ� �ִ� ������ �ϴ� 
	�Լ�. ���� �Է��� string���� �޾ƿ´�.                           

(12)float Get_floatData();
	�Ǽ����� �ش�Ǵ� ���� �޾ƿ;� �ϴ� ��� �������� �Է��� �̷���������� Ȯ���Ͽ�
	atof�Լ��� �Ǽ����� �������ִ� �Լ�.                                            

*/
