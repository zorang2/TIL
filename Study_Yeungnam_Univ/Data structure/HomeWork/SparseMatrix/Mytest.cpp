/*
fast_transpose, COMPARE 함수 선언해야 쓸수있는 코드. 일단 귀찮아서 넘긴다.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TERMS 101

typedef struct { // 희소행렬을 저장할 구조체
	int row; // 행
	int col; // 열
	float value; // 값
} term;


void mmult(term a[], term b[], term d[])
{		// a, b: 입력, d: 출력, d = a * b
	int i, j, column, totald = 0;
	int rows_a = a[0].row, cols_a = a[0].col, totala = a[0].value;
	int cols_b = b[0].col, totalb = b[0].value;
	int row_begin = 1, row = a[1].row, sum = 0; // row: a의 현재 행
	term new_b[MAX_TERMS];

	if (cols_a != b[0].row) {	// a의 열의 수와 b의 행의 수는 동일
		fprintf(stderr, "Incompatible matricses\n"); exit(1);
	}
	fast_transpose(b, new_b);
	// 경계 조건을 설정
	a[totala+1].row = rows_a;
	new_b[totalb+1].row = cols_b;
	new_b[totalb+1].col = 0;

    	for (i = 1; i <= totala; ) {
		column = new_b[1].row;	// b의 현재 열
		for (j = 1; j <= totalb + 1; ) {
		   	// a의 현재 행과 b의 현재 열에 대해 곱셈 수행
			if (a[i].row != row) {  // a의 현재 행을 벗어남.
				storesum(d, &totald, row, column, &sum);
				i = row_begin;	// b는 다음 열로. a는 원 위치로.
				for (; new_b[j].row == column; j++) ;
				column = new_b[j].row;
		   	}
			else if(new_b[j].row != column) {	//b의 현재 열을 벗어남
				storesum(d, &totald, row, column, &sum);
				i = row_begin;	// a는 원 위치
				column = new_b[j].row;	 // b는 다음 열로.
		   	}
			else switch (COMPARE(a[i].col, new_b[j].col)){
				case -1: 	// a[i].col < new_b[j].col. a 증가
			   		i++;	break;
				case 0: 	// 계산 후, a와 b를 모두 진행
			   		sum += (a[i++].value * new_b[j++].value);
					break;
				case 1: 	// a[i].col > new_b[j].col. b 증가
			   		j++;
		   	}
		} // end of j
		for (; a[i].row == row; i++); // b의 모든 원소를 처리한 후,
		row_begin = i;	row = a[i].row; // a의 현재 행을 다음 행으로.
	} /* end of for i <= totala */
	d[0].row = rows_a;
	d[0].col = cols_b; 
	d[0].value = totald;
}
void storesum(term d[], int *totald, int row, int column, int *sum)
{
	/* sum이 0이 아니면, d 배열의 *totald+1 위치에 
		row, column 값과 함께 저장 */
	if (*sum)
		if (*totald < MAX_TERMS) {
		   d[++*totald].row = row;
		   d[*totald].col = column;
		   d[*totald].value = *sum;
		   *sum = 0;
		}
		else {
		   fprintf(stderr, "Numbers of terms in product exceeds %d\n", MAX_TERMS);
		   exit(1);
		}
}
