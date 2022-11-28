#if 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 101
#define max 100
// QUEUE

int queue[MAX];
int front, rear = 0;

typedef struct {                         //term 
	int row;
	int col;
	int value;
} term;


void fast_transpose(term a[], term b[]) {
	int row_terms[MAX];
	int starting_pos[MAX];
	int i, j;
	int num_col = a[0].col;
	int num_terms = a[0].value;

	b[0].row = num_col;
	b[0].col = a[0].row;
	b[0].value = num_terms;

	if (num_terms > 0) {
		for (i = 0; i < num_col; i++) {
			row_terms[i] = 0;  // A row_terms0
			//printf("row_terms[%d]= %d\n", i, row_terms[i]);
		}
		printf("\n\n");
		for (i = 1; i <= num_terms; i++) {
			row_terms[a[i].col]++; // A row_terms1
			printf("row_terms[a[%2d].col]  =row_terms[%d] = %d\n", i, a[i].col, row_terms[a[i].col]);
		}
		printf("\n\n");
		starting_pos[0] = 1;

		for (i = 1; i < num_col; i++) {
			starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
			//printf("starting_pos[%d]= %d\n", i, starting_pos[i]);
		}
		printf("\n\n");
		for (i = 0; i < num_col; i++) {
			//printf("starting_pos[%d]= %d\n", i, starting_pos[i]);
		}
		printf("\n\n");
		for (i = 1; i <= num_terms; i++) {
			j = starting_pos[a[i].col]++;

			printf("j = %2d = starting_pos[a[%2d].col]++ = starting_pos[%d]++\n", j, i, a[i].col);
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}

void counting_sort(int* arr, int size) {

	int count[max];
	for (int i = 0; i < size; i++) {
		printf("a[%d] | %d || ", i, arr[i]);
	}
	printf("\n\n");
	for (int i = 0; i < max; i++) {
		count[i] = 0; // 
	}

	for (int i = 0; i < size; i++) {
		int val = arr[i];
		count[val]++; // 
	}
	for (int i = 0; i < size; i++) {
		printf("row_terms[%d] | %d || ", i, count[i]); // 
	}
	printf("\n\n");
	printf("sorted ");
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < count[i]; j++) {
			printf("%d | ", i);
		}
	}
}

int main() {
	int i, j;
	srand((unsigned int)time(NULL));
	//
	term A[101];
	term B[101];
	int a[100] = { 0 };
	A[0].col = 101; A[0].row = 101; A[0].value = 100;
	for (i = 1; i < MAX; i++)
	{
		A[i].col = i; A[i].row = i; A[i].value = (rand() % 100);
	}


	fast_transpose(A, B);

	printf("Transpose processing has been finished.\n");
	printf("\n\n");

	//printf("%d, %d, 0%d\n", B[0].row, B[0].col, B[0].value);

	//for (i = 1; i < MAX; i++)
	//printf("%d, %d, %d\n", B[i].row, B[i].col, B[i].value);
	for (i = 0; i < 100; i++) {
		a[i] = B[i + 1].value;

	}
	printf("\n\n");

	int size = sizeof(a) / sizeof(a[0]);

	counting_sort(a, size);

	return 0;
}

#endif
