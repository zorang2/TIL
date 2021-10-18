#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct { // 희소행렬을 저장할 구조체
	int row; // 행
	int col; // 열
	float value; // 값
} term;

int Get_intData(); // 정수를 입력받아 리턴해주는 함수
float Get_floatData(); // 실수를 입력받아 리턴해주는 함수

int InputSum(term *r, int total, int row, int col, float sum); // 행렬의 각 계산 결과를 저장해주는 함수
void MatrixCpy(term *a, term *b, int i); // 두 희소행렬을 복사해주는 함수

int Get_MatrixFromFile();   // file에서 데이터를 읽어오는 함수
void Get_MatrixFromUser();  // 희소행렬을 직접입력받기위한 함수
void Get_MatrixValue(term *Matrix, int MaxRow, int MaxCol, int MaxValue); // 희소행렬을 저장해주는 함수
void Get_TransposeMatrix(term *orgMatrix, term *transMatrix, int MaxRow, int MaxCol, int MaxValue); // 전치행렬을 만드는 함수
void Get_ResultOfMultiplication(term *M_A, term *M_B, term *trans, // 두 희소행렬을 곱해주는 함수
								int MaxRowA, int MaxColA, int MaxValueA, int MaxRowB, int MaxColB, int MaxValueB);

void fprint_Matrix(term *Matrix, int MaxR, int MaxC, int MaxV); // 행렬을 출력해주는 함수
void fprint_SpaseMatrix(term *Matrix, int MaxV); // 희소행렬을 출력해주는 함수
void fprint_WholeResult(term *MatrixA, term *MatrixB, term *MatrixT, term *MatrixR, // 사용된 모든 행렬을 출력해주는 함수
					   int MaxRA, int MaxCA, int MaxCB, int MaxA, int MaxB, int MaxR);

int main()
{
	int select, check;

	printf("========================================\n");
	printf("1. 화일로 읽어오기    2. 직접 입력      \n");
	printf("========================================\n");
	select = Get_intData();

	if(select == 1){
		check = Get_MatrixFromFile();
		if(check == 0) {printf("잘못된 파일입니다.\n"); return 0;}
	}

	else if(select == 2){
		Get_MatrixFromUser();
	}

	return 0;
}

void Get_MatrixFromUser()
{
	////////////////////////////////////////////////////////////////////////////////////
	/*곱셈을 할 두 행렬을 직접입력받아오는 경우 호출되는 함수이다. 이 함수는 행렬A,B의 /
	/행/열 및 원소의 갯수를 받아온 후 각 원소를 저장한다.저장이 끝나면 B행렬을 전치행렬/
	/로 변환한 후 곱셈을 하도록 함수를 호출한다.                                      */
	////////////////////////////////////////////////////////////////////////////////////

	int MRowA, MColA, MValueA; // 행렬A의 행/열/값의 수를 저장할 변수
	int MRowB, MColB, MValueB; // 행렬B의 행/열/값의 수를 저장할 변수
	term *Matrix_A; // 행렬 A
	term *Matrix_B; // 행렬 B
	term *Matrix_trans; // 행렬B의 전치행렬

	/*행렬A의 행/열/값의 갯수를 받아오는 부분*/
	printf("행렬A의 행값을 입력하시오 : ");
	MRowA = Get_intData();
	printf("행렬A의 열값을 입력하시오 : ");
	MColA = Get_intData();
	printf("행렬A의 value 갯수를 입력하시오 : ");
	MValueA = Get_intData();

	/*행렬A의 희소행렬을 생성하는 부분*/
	Matrix_A = (term *)malloc(MValueA * sizeof(term));
	Get_MatrixValue(Matrix_A, MRowA, MColA, MValueA);

	/*행렬B의 행/열/값의 갯수를 받아오는 부분*/
	MRowB = MColA; // 행렬B의 행값은 행렬A의 열값과 동일
	printf("행렬B의 행값은 %d 입니다.\n", MRowB);
	printf("행렬B의 열값을 입력하시오 : ");
	MColB = Get_intData();
	printf("행렬B의 value 갯수를 입력하시오 : ");
	MValueB = Get_intData();

	/*행렬B의 희소행렬을 생성하는 부분*/
	Matrix_B = (term *)malloc(MValueB * sizeof(term));
	Get_MatrixValue(Matrix_B, MRowB, MColB, MValueB);

	/* 행렬B의 전치행렬을 생성하는 부분*/
	Matrix_trans = (term *)malloc(MValueB * sizeof(term)); 
	Get_TransposeMatrix(Matrix_B, Matrix_trans, MRowB, MColB, MValueB);

	/*행렬 A,B를 전치행렬을 이용하여 곱셈수행 부분*/
	Get_ResultOfMultiplication(Matrix_A, Matrix_B, Matrix_trans, MRowA, MColA, MValueA, MRowB, MColB, MValueB);

	free(Matrix_A);
	free(Matrix_B);
	free(Matrix_trans);
}

int Get_MatrixFromFile()
{
	////////////////////////////////////////////////////////////////////////////////////
	/*이 함수는 파일로 부터 행렬을 받아오는 경우 사용되는 함수이다.함수가 호출되면 파일/
	/array.dat를 열어 첫 열에서 행/열/원소의 갯수를 받아와서 저장한다.그 후 원소의 갯수/
	/에따라서 파일상에서 각 원소 저장에 필요한 데이터를 받아온다. 이러한 방식으로 두 행/
	/렬을 모두 받아오면 전치행렬을 생성하고 곱셈을 하기위한 함수를 호출해 준다.       */
	////////////////////////////////////////////////////////////////////////////////////

	term *MatrixA, *MatrixB, *Matrix_trans;
	int MRowA, MRowB, MColA, MColB, MValA, MValB;
	int wcnt, mcnt, MV, i;
	char strbuf[10];
	FILE *in;

	in = fopen("array.dat", "r"); // 행렬이 저장된 파일을 오픈한다.
	wcnt = 0;

	while(wcnt < 2){
		// 최대 행 및 열의 값, 원소수를 받아오는 부분
		if(fscanf(in, "%s", strbuf)){

			// 행렬의 행사이즈를 받아오는 부분.
			if(wcnt == 0){ // A행렬
				MRowA = atoi(strbuf);
				if(MRowA < 1) { fclose(in); return 0; } // 행 사이즈는 1보다 작으면 안된다.
			}
			else{ // B행렬
				MRowB = atoi(strbuf);
				if(MRowB < 1) { fclose(in); return 0; }
			}
		}
		else { fclose(in); return 0; }

			// 행렬의 열사이즈를 받아오는 부분.
		if(fscanf(in, "%s", strbuf)){
			if(wcnt == 0){ // A행렬
				MColA = atoi(strbuf);
				if(MColA < 1) { fclose(in); return 0; } // 열 사이즈는 1보다 작으면 안된다.
			}
			else{ // B행렬
				MColB = atoi(strbuf);
				if(MColB < 1) { fclose(in); return 0; }
			}
		}
		else { fclose(in); return 0; }

			// 원소의 갯수를 받아오는 부분
		if(fscanf(in, "%s", strbuf)){
			if(wcnt == 0){ // A행렬
				MValA = atoi(strbuf);
				if(MValA < 0) { fclose(in); return 0; } // 원소의 수는 음수이면 안된다.
			}
			else{ // B행렬
				MValB = atoi(strbuf);
				if(MValB < 0) { fclose(in); return 0; }
			}
		} 
		else { fclose(in); return 0; }

		// end of get MaxData

		mcnt = 0;
		// 원소의 갯수를 받아왔으므로 이를 이용하여 희소행렬 배열의 사이즈를 잡아준다.
		if(wcnt == 0) {
			MV = MValA;  // A행렬 저장을 위한 공간을 메모리에 잡아준다.
			MatrixA = (term *)malloc((MValA) * sizeof(term));
		}
		else {
			MV = MValB; // B행렬 저장을 위한 공간을 메모리에 잡아준다.
			MatrixB = (term *)malloc((MValB) * sizeof(term));
		}

		// 희소행렬을 생성하는 부분.
		while(mcnt < MV){ // while문은 원소의 갯수만큼만 동작한다.

			if(fscanf(in, "%s", strbuf)){

				// 행을 받아오는 부분. 행은 행렬의 사이즈를 넘어서면 안되며, 음수도 나오면 안된다.
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

			// 열을 받아오는 부분. 열은 행렬의 사이즈를 넘어서면 안되며, 음수도 나오면 안된다.
			if(fscanf(in, "%s", strbuf)){
				if(wcnt == 0){ // get matrixA data
					MatrixA[mcnt].col = atoi(strbuf);
					if(MatrixA[mcnt].col >= MColA) { fclose(in); return 0; }
					else if(MatrixA[mcnt].col < 0) { fclose(in); return 0; }

					for(i = 0; i < mcnt; i++){ // 열까지 받은 후에는 정렬된 데이터인지 확인하여 준다.
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

			// 원소를 받아오는 부분. 원소는 0이면 희소행렬의 정의 위반이므로 저장하지 않는다. 
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

	/* 행렬B의 전치행렬을 생성하는 부분*/
	Matrix_trans = (term *)malloc(MValB * sizeof(term)); 
	Get_TransposeMatrix(MatrixB, Matrix_trans, MRowB, MColB, MValB);

	/*행렬 A,B를 전치행렬을 이용하여 곱셈수행 부분*/
	Get_ResultOfMultiplication(MatrixA, MatrixB, Matrix_trans, MRowA, MColA, MValA, MRowB, MColB, MValB);

	free(MatrixA);
	free(MatrixB);
	free(Matrix_trans);

	return 1;
}

void Get_MatrixValue(term *Matrix, int MaxRow, int MaxCol, int MaxValue)
{
	////////////////////////////////////////////////////////////////////////////////////
	/*곱셈 계산을 할 두 행렬을 받아 오는 함수. 최초입력된 행/열 값을 이용하여 이를 넘는/
	/값이 입력될 경우는 오류처리를 하고 다시 입력하게 한다. 입력된 value의 갯수 만큼 만/
	/for문을 수행하여 각 값을 입력받아온다.                                           */
	////////////////////////////////////////////////////////////////////////////////////

	int j;
	int i = 0;

	while(i < MaxValue){ // MaxValue 만큼 만 수행된다.
		int tRow, tCol, flag = 1;
		printf("입력할 Value의 행 값을 입력하시오 : ");
		tRow = Get_intData();
		printf("입력할 Value의 열 값을 입력하시오 : ");
		tCol = Get_intData();
		
		if(tRow < MaxRow){ // 최대 행값을 확인한다.
			if(tCol < MaxCol){ // 최대 열값을 확인한다. 
				Matrix[i].col = tCol;
				Matrix[i].row = tRow;

				for(j = 0; j < i; j++){ // 희소행렬에 행/열값이 정렬되서 들어갔는지를 확인한다.
					if(Matrix[j].row == Matrix[i].row){
						if(Matrix[j].col >= Matrix[i].col){
							printf("잘못 입력하였습니다. 다시 입력하십시오.\n");
							flag = 0;
						}
					}
					else if(Matrix[j].row > Matrix[i].row){
						printf("잘못 입력하였습니다. 다시 입력하십시오.\n");
						flag = 0;
					}
				}

				if(flag){
					printf("Value를 입력하시오 : ");
					Matrix[i].value = Get_floatData();
					i++; // 입력이 정상적으로 이루어진 경우 다음 값을 입력받기 위해 i값 증가시킴.
				}
				else continue;
			}

			else printf("열값을 잘못 입력하였습니다.\n");
		} // end of if

		else printf("행값을 잘못 입력하였습니다.\n");
	} // end of while

}

void Get_TransposeMatrix(term *orgMatrix, term *transMatrix, int MaxRow, int MaxCol, int MaxValue)
{
	//////////////////////////////////////////////////////////////////////////////////////////////
	/* 행렬B의 전치행렬을 구해주는 함수. row_terms는 입력되있는 각 행에 해당하는 value의 갯수를  /
	/ 저장하는 배열이며, starting_pos는 전치행렬의 각 행에 행을 기준으로 정렬되면서 저장될수 있도/
	/ 록 현재의 행이 전치행렬에서 저장될 위치를 지정해주는 배열이다. 최초 starting_pos는 row_term/
	/ 을 이용하여 초기값을 입력하고, 해당하는 행에 데이터가 들어가면 값을 증가시키면서 시작위치를/
	/ 유지해준다. 전치행렬은 row와 col을 바꾸어 저장한 행렬이 된다.                             */
	//////////////////////////////////////////////////////////////////////////////////////////////

	int *row_terms, *starting_pos;
	int i, j;
	int MRowT, MColT, MValueT; // 전치행렬의 행/열/원소 갯수를 저장할 변수

	row_terms = (int *)malloc(MaxCol * sizeof(int));
	starting_pos = (int *)malloc(MaxCol * sizeof(int));

	/*전치행렬은 행렬B의 열,행,원소의 갯수를 행,열,원소의 갯수로 한다. */
	MRowT = MaxCol;
	MColT = MaxRow;
	MValueT = MaxValue;

	if(MaxValue > 0){ // 원소가 존재하는 경우 수행된다.

		for(i = 0; i < MaxCol; i++) row_terms[i] = 0; // row_terms 초기화
		for(i = 0; i < MaxValue; i++) row_terms[orgMatrix[i].col]++; // row_terms에 각 행 원소의 갯수 저장.

		starting_pos[0] = 0;  // 첫 저장 위치는 0으로 초기화

		for(i = 1; i < MaxCol; i++) // row_terms를 이용하여 각 행의 시작 위치 저장.
			starting_pos[i] = starting_pos[i-1] + row_terms[i-1];

		for(i = 0; i < MaxValue; i++){ // 전치행렬에 행렬B의 원소수 만큼 각 값을 저장한다.
			j = starting_pos[orgMatrix[i].col]++; // 시작위치를 j에 저장하고 starting_pos값 증가시킴.
			transMatrix[j].row = orgMatrix[i].col; //전치행렬의 행에 행렬B의 열값을 저장.
			transMatrix[j].col = orgMatrix[i].row; //전치행렬의 열에 행렬B의 행값을 저장.
			transMatrix[j].value = orgMatrix[i].value; //원소 저장.
		} // end of for

	} // end of if

	free(row_terms);
	free(starting_pos);
}

void Get_ResultOfMultiplication(term *M_A, term *M_B, term *trans,
								int MaxRowA, int MaxColA, int MaxValueA, int MaxRowB, int MaxColB, int MaxValueB)
{
	//////////////////////////////////////////////////////////////////////////////////////////////////
	/*행렬A와 행렬B를 전치행렬을 이용하여 곱셈 후 그 결과를 Result에 저장해주는 함수. 행렬의 곱셈은  /
	/ 첫 행렬은 행순서로 두번째 행렬은 열 순서로 이동하면서 곱셈을 수행하게 되므로 전치행렬을 이용하 /
	/ 면 곱셈을 하기가 수월해 진다. 이 함수에서는 전치행렬을 파라미터로 받아와 곱셈에 이용하며, 시작 /
	/ 행의 각 열값과 대응하는 전치행렬의 해당하는 행의 열값들을 곱한 후 최종적으로 더해서 결과를 산출/
	/ 하게 된다. 곱셈을 수행하는 행렬A의 행값은 변수 row로 유지하며, 해당 행이 희소행렬상에서 시작되 /
	/ 는 위치는 변수 row_begin으로 유지한다. 전치행렬의 계산이 수행되고있는 행은 변수 col로 유지하며,/
	/ 해당 행에서의 열은 j로 유지해 준다. 행렬A와 전치행렬의 열값이 동일한 경우로서 원소가 존재하면, /
	/ 곱셈을 하여 sum에 더해준다. 계산에 이용되는 행렬은 희소행렬로 저장되어 있으므로 행렬A,B의 원소 /
	/ 갯수 만큼만 각 for문을 수행하면 된다. 저장되는 행렬 Result도 희소행렬이지만 초기에는 원소가 몇 /
	/ 개 들어가야 하는지 알 수 없으므로 행렬A,B의 원소수를 합한 만큼 메모리를 잡아주고 모자르게 되는 /
	/ 경우는 현재 크기의 2배만큼 메모리를 늘려주는 식으로 희소행렬을 잡아준다.                      */
	//////////////////////////////////////////////////////////////////////////////////////////////////

	int i, j, total, row_Begin, row, col;
	/*i는 행렬A의 열을 따라갈 변수 
	  j는 전치행렬의 열을 따라갈 변수
	  total은 Result행렬의 원소의 갯수를 위한 변수
	  row_begin은 곱셈을 수행할 해당 행의 희소행렬 상의 위치를 유지할 변수
	  row는 현재 곱셈이 수행되고 있는 형렬A 상의 행을 나타낼 변수
	  col은 현재 곱셈이 수행되고 있는 전치행렬 상의 행을 나타낼 변수*/

	int MaxResult; // Result 행렬의 크기를 나타낼 변수 
	float sum; // 각 곱셈의 결과들을 더해서 저장할 변수
	term *Result, *temp;

	total = 0;
	row_Begin = 0; // 시작 행의 위치
	row = M_A[0].row; // 시작 행의 지정
	sum = 0;
	MaxResult = MaxValueA + MaxValueB; // 초기 결과행렬의 크기

	if(MaxColA != MaxRowB){ // 행렬A의 열과 행렬B의 행이 다르면 오류처리
		printf("잘못된 행렬입니다.\n");
		return;
	}

	Result = (term *)malloc((MaxResult) * sizeof(term));

	for(i = 0; i < MaxValueA;){ // 행렬A의 원소 수 만큼 수행
		col = trans[0].row; // 전치행렬의 계산을 시작할 행 지정.

		for(j = 0; j <= MaxValueB;){ 
			// 전치행렬의 원소수 + 1 만큼 수행. 결과행렬에 저장하는 경우를 위해 한번 더 for문이 도는 것임.

			if(M_A[i].row != row){ // 계산 될 행이 아닌경우.
				if(sum != 0){ // 이전까지 더해진 값이 있다면 이를 저장한다.
					if(total < MaxResult){ // 결과행렬의 공간이 남아있는 경우
						total = InputSum(Result, total, row, col, sum); // 곱셈의 결과를 결과행렬에 저장
						sum = 0; // 초기화
					}
					else { // 결과 행렬에 공간이 부족한 경우 메모리를 두배로 잡아준 후 저장.
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

				i = row_Begin; // 행렬A의 계산 수행 위치를 다시 잡아줌
				for(;trans[j].row == col; j++); // 전치행렬의 다음 행으로 이동
				col = trans[j].row; // 전치행렬의 계산 시작위치 다시 지정.
			} // end of if

			else if(trans[j].row != col){ // 계산될 전치행렬의 행이 아닌경우.
				if(sum != 0){ // 계산결과가 존재한다면 결과행렬에 저장해줌.
					if(total < MaxResult){
						total = InputSum(Result, total, row, col, sum);
						sum = 0;
					}
					else { // 결과행렬의 공간이 부족한 경우 두배로 늘려주고 결과를 저장해줌.
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
				i = row_Begin; // 행렬A의 계산 시작 위치 지정.
				col = trans[j].row; // 전치행렬의 계산 시작 위치 다시 지정.
			} // end of else if

			else{ // 계산될 행이 존재한다면 계산을 수행하는 부분.
				if(M_A[i].col < trans[j].col) { i++; } // 전치행렬의 열보다 행렬A의 열이 작은 경우 행렬A의 i값을 증가시킴.

				else if(M_A[i].col == trans[j].col){ // 행렬A의 열과 전치행렬의 열이 동일하다면 계산 수행.
					sum += (M_A[i].value * trans[j].value); i++; j++;
				}
			
				else { j++; } // 행렬A의 열값이 큰경우는 전치행렬의 j값을 증가시킴.
			} // end of else

		} // end of B for

		for(; M_A[i].row == row; i++); // 다음 계산을 우해 행렬A의 다음 행으로 이동.
		row_Begin = i; // 계산할 행의 희소행렬 상의 시작위치를 다시 지정.
		row = M_A[i].row; // 계산할 행값을 다시 지정.

	} // end of A for

	fprint_WholeResult(M_A, M_B, trans, Result, MaxRowA, MaxColA, MaxColB, MaxValueA, MaxValueB, total);
			// 모든 결과를 화면에 출력.
	free(Result);
}

int InputSum(term *r, int total, int row, int col, float sum)
{
	////////////////////////////////////////////////////////////
	/*행렬A 및 전치행렬을 이용하여 곱셈을 수행한 결과를 Result /
	/ 행렬에 저장해주는 함수.                                 */
	////////////////////////////////////////////////////////////

	r[total].row = row;
	r[total].col = col;
	r[total].value = sum;
	total++; // Result행렬의 원소수를 증가시킴.

	return total;
}

void MatrixCpy(term *a, term *b, int i)
{
	///////////////////////////////////////////////
	/*희소행렬a를 희소행렬b에 복사하는 함수.     */
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
	/*프로그램에 사용된 모든 희소행렬 및 정상적인 행렬의 모습을 출력하는 함수.   */
	///////////////////////////////////////////////////////////////////////////////

	FILE *out;
	

	/*희소행렬들을 출력*/
	out = fopen("a.out", "w"); // 출력 file의 이름은 a.out이다.
	fprintf(out, "\n입력한 행렬A의 희소행렬 표현 \n");
	fclose(out);
	fprint_SpaseMatrix(MatrixA, MaxA);
	out = fopen("a.out", "a");
	fprintf(out, "입력한 행렬B의 희소행렬 표현 \n");
	fclose(out);
	fprint_SpaseMatrix(MatrixB, MaxB);
	out = fopen("a.out", "a");
	fprintf(out, "입력한 행렬B의 전치행렬 표현 \n");
	fclose(out);
	fprint_SpaseMatrix(MatrixT, MaxB);
	out = fopen("a.out", "a");
	fprintf(out, "계산 결과행렬의 희소행렬 표현 \n");
	fclose(out);
	fprint_SpaseMatrix(MatrixR, MaxR);

	/*행렬A, 행렬B, 결과행렬을 출력*/
	out = fopen("a.out", "a");
	fprintf(out, "입력한 두 행렬 : \n");
	fclose(out);
	fprint_Matrix(MatrixA, MaxRA, MaxCA, MaxA);
	fprint_Matrix(MatrixB, MaxCA, MaxCB, MaxB);
	out = fopen("a.out", "a");
	fprintf(out, "계산 결과 행렬 : \n");
	fclose(out);
	fprint_Matrix(MatrixR, MaxRA, MaxCB, MaxR);
	printf("결과File a.out이 생성되었습니다.\n");
}

void fprint_Matrix(term *Matrix, int MaxR, int MaxC, int MaxV)
{
	//////////////////////////////////////////////////////////
	/*행렬의 전체 모습을 출력하는 함수. 희소행렬 상에 원소가 /
	/ 없는 경우는 0을 출력하여 준다.                        */
	//////////////////////////////////////////////////////////

	int i, j, k;
	float t;

	FILE *out;
	out = fopen("a.out", "a");

	t = 0; // 희소행렬상에 원소가 없는 경우 출력될 값.
	k = 0;
	
	for(i = 0; i < MaxR; i++){ // 최대 행 만큼 수행
		for(j = 0; j < MaxC; j++){ // 최대 열 만큼 수행
			if(k < MaxV){ // 희소행렬상에 아직 원소가 있는 경우 
				// 현재 행/열에 원소가 있다면 그 값을 출력하여 준다.
				if(Matrix[k].row == i && Matrix[k].col == j){ fprintf(out, "%f  ", Matrix[k].value); k++; }
				else fprintf(out, "%f  ", t); // 원소가 없는 경우 0을 출력.
			}
			else fprintf(out, "%f  ", t); // 더이상 희소행렬에 원소가 없다면 남은 부분에는 0을 출력.
		}
		fprintf(out, "\n");
	}
	fprintf(out, "\n");

	fclose(out);
}

void fprint_SpaseMatrix(term *Matrix, int MaxV)
{
	//////////////////////////////////////////////////////////
	/*희소행렬을 출력하여 주는 함수.                        */
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
	/*정수값을 입력받아야 하는 경우 정상적인 입력이 이루어 졌는 지 검사 /
	/ 한 후 atoi함수를 이용하여 해당 정수값을 반화하여 주는 역할을 하는 /
	/ 함수. 최초 입력은 string으로 받아온다.                           */
	/////////////////////////////////////////////////////////////////////

	char temp[10];  // 입력 받을 문자열을 저장할 배열
	int flag;
	flag = 1;

	while(flag){
		int len, i;
		scanf("%s", temp);
		len = strlen(temp); // 입력받은 문자열의 길이를 알아옴.
		flag = 0;

		for(i = 0; i < len;){ // 입력받은 각 문자들이 정수에 해당하는지 검사.
			if(temp[i] < 48 || temp[i] > 57){ // 0~9에 해당하지 않는 경우는 다시 입력받음.
				printf("잘못 입력하였습니다. 다시 입력하십시오.\n");
				flag = 1; break;
			} // end of if
			else i++;
		} // end of for
	} // end of while

	return atoi(temp); // 정상적인 입력이 이루어졌다면 atoi함수를 이용하여 리턴시킴.
}

float Get_floatData()
{
	////////////////////////////////////////////////////////////////////////////////////
	/*실수형에 해당되는 값을 받아와야 하는 경우 정상적인 입력이 이루어졌는지룰 확인하여/
	/ atof함수로 실수값을 리턴해주는 함수.                                            */
	////////////////////////////////////////////////////////////////////////////////////

	char temp[10];
	int flag;
	flag = 1;

	while(flag){
		int len, i, dotcnt, mnscnt; // dotcnt는 '.'이 올바른 위치에 하나만 들어가는 것을 조절하는 변수.
		                            // mnscnt는 '-'부호가 올바르게 쓰여졌는지를 확인하는 변수.
		scanf("%s", temp);
		len = strlen(temp);
		flag = dotcnt = mnscnt = 0;

		for(i = 0; i < len;){
			if((len == 1) && (temp[0] < 48 || temp[0] > 57)){ // 한개의 문자만 입력한 경우는 0~9에 해당하는 경우만 
				                                              // 올바른 입력으로 간주한다.
				printf("잘못 입력하였습니다. 다시 입력하십시오.\n");
				flag = 1; break;
			}

			else{ // 한개를 초과하는 문자가 입력된 경우.
				if(temp[i] < 48 || temp[i] > 57){ // 0~9에 해당되지 않는 문자가 존재하는 경우.
					if(i == 0 && temp[i] == '-'){ mnscnt++; i++; } // 첫 문자로서는 '-'값만이 0~9를 제외하고 들어갈 수 있다.

					else if(i != 0 && temp[i] == '.' && dotcnt == 0) { // 첫 문자가 아닌 경우는 '.'이 들어갈 수 있다.
						if(mnscnt > 0 && i == 1){ // '.'은 '-'가 쓰여진 경우는 두번째 자리에 올 수 없다.
							printf("잘못 입력하였습니다. 다시 입력하십시오.\n");
							flag = 1; break;
						}
						else{ dotcnt++; i++; } // '.'은 하나만 들어갈 수 있으므로 이를 표시해준다.
					}

					else{
						printf("잘못 입력하였습니다. 다시 입력하십시오.\n");
						flag = 1; break;
					}
				} // end of if

				else i++;
			} // end of else
		} // end of for
	} // end of while

	return (float)atof(temp); // 정상적인 입력이 이루어진 경우는 atof를 이용하여 리턴해준다.
}


///////////////////////////////////////////////////
/*시간,공간복잡도 계산 및 소스코드 설명.         */
///////////////////////////////////////////////////
/*

1. 공간복잡도의 계산
 이번 프로그램에서는 4개의 동적배열이 사용되었다. A행렬, B행렬 및 전치행렬, A,B의 곱셈 결과를 저장하게 될 구조체 배열이며, 
 이중 전치행렬은 B행렬과 동일한 사이즈로 잡혀있다.그외 지역변수들은 Big-Oh notation으로 공간 복잡도를 표현하는 경우 상수개 
 사용되었으므로 제외해도 상관이 없다. 4개의 동적배열 중 전치행렬은 B행렬과 사이즈가 항상 동일하므로 B행렬의 사이즈를 n2라 
 할때 2*(n2)가되어 Big-Oh로 표현하는 경우 복잡도에 영향이 없다. 따라서 A행렬 사이즈를 n1, 결과행렬사이즈를 n3이라 할때 
 프로그램의 공간 복잡도를 Big-Oh로 표현하면 O(n1+n2+n3)이 된다.

2. 시간복잡도의 계산
 희소행렬의 곱셈 프로그램은 곱셈을 수행하는 부분이 핵심이며, 이 부분의 시간 복잡도가 프로그램의 성능을 좌우하게된다. 행렬의
 곱셈에 관여되는 함수는 총 4개이며, 이 중 A행렬의 행 값들과 B전치행렬의 행값들을 곱하여 더한 결과를 결과행렬에 저장하는 함수인
 InputSum의 경우는 상수시간에 수행되어 시간복잡도에 영향이 없으며, 결과행렬의 메모리 확장을 위한 과정에서 사용되는 데이터 교환
 함수인 MatrixCpy도 상수시간에 수행되므로 시간복잡도 계산에서 제외한다. 남은 것은 전치행렬을 만드는 Get_TransposeMatrix와 곱셈을
 수행하는 ResultOfMultiplication이다. 전치행렬을 만드는 작업은 한번만 하면 되므로 이를 먼저 계산한다. 우선 전치행렬을 계산하는
 함수에서는 4개의 for문이 존재하며, 이는 각각 MaxCol, MaxValue, MaxCol, MaxValue 만큼 수행된다. 여기서 MaxCol은 B행렬의 열사이즈
 를 나타내는 것이며 MaxValue는 원소의 수를 나타낸다. 반복문 안의 문장은 상수시간에 수행되므로 시간복잡도에 영향이 없고, for문은
 2*MaxCol + 2*MaxValue 만큼 수행되므로 Big-Oh notation으로 표현하면 O(MaxCol + MaxValue)가 된다. 다음으로 곱셈 함수를 분석하면,
 여기에는 for문이 이중으로 들어가 있으며, 상위 for문은 MaxValueA(A행렬 원소수), 하위 for문은 MaxValueB(B행렬 원소수)를 종료 조건
 으로 한다. 하지만 상위 for문은 i값이 재설정 되는 경우가 있으므로 이를 고려해야 하는데, K를 A행렬의 현재 행에 있는 항의 총 수라면
 i가 A행렬의 다음 행으로 이동하기 전에 많아야 k번 만큼 증가할 수 있다. 이 경우 i를 재설정하는 동시에 col은 다음 열로 보내게 된다.
 따라서 이 재설정은 많아야 MaxColB(B행렬의 열의 수)번이고, i의 최대 총 증가량은 MaxColB*k가 된다. 그에따라 상위 for문의 최대
 반복수는 MaxColB+MaxColB*k+MaxValueB이다. 현재 행이 곱해지는 동안 하위 fora문에 소요되는 시간은 O(MaxColB*k+MaxValueB)이며, 다음
 행으로 진행하는 데 걸리는 시간은 O(k)가 된다. 그러므로 상위 for문이 한번 반복하는 데 걸리는 시간은 O(MaxColB*k+MaxValueB)이다.
 그결과 전체 소요시간은 O(sigma(MaxColB*k+MaxValueB))=O(MaxColB*MaxValueA + MaxRowA*MaxValueB) 이다. 이 결과에 따라 최악의 시간
 복잡도를 구해보면, MaxValueA<=MaxRowA*MaxColA, MaxValueB<=MaxRowB*MaxColA 이므로, 최악의 경우 O(MaxRowA*MaxColA*MaxColB)의 시간
 복잡도를 같게된다.

3. 사용된 함수의 설명
(1) void Get_MatrixFromUser();
	곱셈을 할 두 행렬을 직접입력받아오는 경우 호출되는 함수이다. 이 함수는 행렬A,B의 
	행/열 및 원소의 갯수를 받아온 후 각 원소를 저장한다.저장이 끝나면 B행렬을 전치행렬
	로 변환한 후 곱셈을 하도록 함수를 호출한다.                                      

(2) int Get_MatrixFromFile(); 
	이 함수는 파일로 부터 행렬을 받아오는 경우 사용되는 함수이다.함수가 호출되면 파일
	array.dat를 열어 첫 열에서 행/열/원소의 갯수를 받아와서 저장한다.그 후 원소의 갯수
	에따라서 파일상에서 각 원소 저장에 필요한 데이터를 받아온다. 이러한 방식으로 두 행
	렬을 모두 받아오면 전치행렬을 생성하고 곱셈을 하기위한 함수를 호출해 준다.       

(3) void Get_MatrixValue(term *Matrix, int MaxRow, int MaxCol, int MaxValue);
	곱셈 계산을 할 두 행렬을 받아 오는 함수. 최초입력된 행/열 값을 이용하여 이를 넘는
	값이 입력될 경우는 오류처리를 하고 다시 입력하게 한다. 입력된 value의 갯수 만큼 만
	for문을 수행하여 각 값을 입력받아온다.                                           

(4) void Get_TransposeMatrix(term *orgMatrix, term *transMatrix, int MaxRow, int MaxCol, int MaxValue);
	행렬B의 전치행렬을 구해주는 함수. row_terms는 입력되있는 각 행에 해당하는 value의 갯수를 
	저장하는 배열이며, starting_pos는 전치행렬의 각 행에 행을 기준으로 정렬되면서 저장될수 있도
	록 현재의 행이 전치행렬에서 저장될 위치를 지정해주는 배열이다. 최초 starting_pos는 row_term
	을 이용하여 초기값을 입력하고, 해당하는 행에 데이터가 들어가면 값을 증가시키면서 시작위치를
	유지해준다. 전치행렬은 row와 col을 바꾸어 저장한 행렬이 된다.                             

(5) void Get_ResultOfMultiplication(term *M_A, term *M_B, term *trans, int MaxRowA, int MaxColA, int MaxValueA, int MaxRowB, int MaxColB, int MaxValueB);
	행렬A와 행렬B를 전치행렬을 이용하여 곱셈 후 그 결과를 Result에 저장해주는 함수. 행렬의 곱셈은  
	첫 행렬은 행순서로 두번째 행렬은 열 순서로 이동하면서 곱셈을 수행하게 되므로 전치행렬을 이용하 
	면 곱셈을 하기가 수월해 진다. 이 함수에서는 전치행렬을 파라미터로 받아와 곱셈에 이용하며, 시작 
	행의 각 열값과 대응하는 전치행렬의 해당하는 행의 열값들을 곱한 후 최종적으로 더해서 결과를 산출
	하게 된다. 곱셈을 수행하는 행렬A의 행값은 변수 row로 유지하며, 해당 행이 희소행렬상에서 시작되 
	는 위치는 변수 row_begin으로 유지한다. 전치행렬의 계산이 수행되고있는 행은 변수 col로 유지하며,
	해당 행에서의 열은 j로 유지해 준다. 행렬A와 전치행렬의 열값이 동일한 경우로서 원소가 존재하면, 
	곱셈을 하여 sum에 더해준다. 계산에 이용되는 행렬은 희소행렬로 저장되어 있으므로 행렬A,B의 원소 
	갯수 만큼만 각 for문을 수행하면 된다. 저장되는 행렬 Result도 희소행렬이지만 초기에는 원소가 몇 
	개 들어가야 하는지 알 수 없으므로 행렬A,B의 원소수를 합한 만큼 메모리를 잡아주고 모자르게 되는
	경우는 현재 크기의 2배만큼 메모리를 늘려주는 식으로 희소행렬을 잡아준다.                      

(6) int InputSum(term *r, int total, int row, int col, float sum);
	행렬A 및 전치행렬을 이용하여 곱셈을 수행한 결과를 Result 
	행렬에 저장해주는 함수.                                 

(7) void MatrixCpy(term *a, term *b, int i);
	희소행렬a를 희소행렬b에 복사하는 함수.     

(8) void fprint_Matrix(term *Matrix, int MaxR, int MaxC, int MaxV);
	행렬의 전체 모습을 출력하는 함수. 희소행렬 상에 원소가
	없는 경우는 0을 출력하여 준다.                        

(9) void fprint_SpaseMatrix(term *Matrix, int MaxV);
	희소행렬을 출력하여 주는 함수.                        

(10)void fprint_WholeResult(term *MatrixA, term *MatrixB, term *MatrixT, term *MatrixR, int MaxRA, int MaxCA, int MaxCB, int MaxA, int MaxB, int MaxR);
	프로그램에 사용된 모든 희소행렬 및 정상적인 행렬의 모습을 출력하는 함수.   

(11)int Get_intData();
	정수값을 입력받아야 하는 경우 정상적인 입력이 이루어 졌는 지 검사 
	한 후 atoi함수를 이용하여 해당 정수값을 반화하여 주는 역할을 하는 
	함수. 최초 입력은 string으로 받아온다.                           

(12)float Get_floatData();
	실수형에 해당되는 값을 받아와야 하는 경우 정상적인 입력이 이루어졌는지룰 확인하여
	atof함수로 실수값을 리턴해주는 함수.                                            

*/
