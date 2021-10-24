#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) =(t))

void sort(int[], int); /*selection sort*/

void main() //�׳� run�ϸ� ���ư�.
{
	int i, n;
	int list[MAX_SIZE];
	printf("Enter the number of numbers to generate: ");
	scanf("%d", &n);
	if (n < 1 || n > MAX_SIZE) {
		fprintf(stderr, "Improper value of n\n");
		exit (EXIT_FAILURE);
	}
	for (i = 0; i < n; i++) {
		list[i] = rand() % 1000;
		printf("%d ", list[i]); //n���� ������ random�ϰ� ����.
	}
	sort(list, n); //sort�Լ� ȣ��. ���ڴ� �迭�� ������ ����
	printf("\nSorted array: \n");
	for (i = 0; i < n; i++) //���ĵ� ������ ���
		printf("%d ", list[i]);
	printf("\n");
}

void sort(int list[], int n)
{
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) { // list[i]���� list[n-1]���� ����.
		min = i;					// i�� �� �ּҰ��� �ʱ�ȭ
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j; // �� ���� ���� ������ �ּҰ��� �̰�����..
		SWAP(list[i], list[min], temp); // �ּҰ��� i�� ������ ��ü
	}
}


/*
#include <stdio.h>
#include <math.h>
#define MAX_SIZE 101
#define SWAP (x, y, t)  ( (t) = (x), (x) = (y), (y) = (t) )
void sort (int [], int); /* selection sort*/
/*
void main(void)
{
    int i, n;
    int list[MAX_SIZE];
    printf("Enter the number of numbers to generate: ");
    scanf("%d", &n);
    if(n < 1 || n > MAX_SIZE) {
        fprintf(stderr, "Improper value of n\n");
        exit(EXIT_FAILURE);
    }
    
}
*/