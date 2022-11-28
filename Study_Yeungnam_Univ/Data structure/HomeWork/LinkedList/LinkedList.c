#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;

typedef struct Node{
	element data;
	struct Node* next;
}Node;

typedef struct List{
	Node* head;
	Node* tail;
}List;

void init_list(List* lp){ //����Ʈ�� �ʱ�ȭ�մϴ�. 
	lp->head = (Node*)malloc(sizeof(Node));
	lp->tail = (Node*)malloc(sizeof(Node));
	lp->head->next = lp->tail;
	lp->tail->next = NULL;
}

void Append(List* lp, element _data){ //����Ʈ�� �������� ��带 �����մϴ�. 
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = _data;
	newNode->next = NULL;
	
	if(lp->head->next == lp->tail){ //����Ʈ�� ���Ұ� ���� �� 
		lp->head->next = newNode;
		newNode->next = lp->tail;
	}
	
	else{
		Node* temp = lp->head;
		while(temp->next != lp->tail){ //tail ������ ���߰� ��� ����. 
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = lp->tail;
	}
}

List* merge(List* a, List* b){ //����Ʈ �ΰ��� �����Ͽ� �����մϴ�. 
	
	List* result = (List*)malloc(sizeof(List)); //return�� ����Ʈ�� ���� ����� 
	init_list(result);
	result->head->next = result->tail;
	result->tail->next = NULL;
	
	Node* ap, *bp, *rp;
	ap = a->head->next; //a ����Ʈ�� ��ȸ�� �����͸� �����ϰ� 
	bp = b->head->next; //b ����Ʈ�� ��ȸ�� �����͸� ������ �� 
	rp = result->head; //return�� ����Ʈ�� ������� �����͸� �����մϴ�. 
	
	while(ap->next != NULL && bp->next != NULL){
		if(ap->data < bp->data){ //a�� ���� b�� ������ ������ 
			rp->next = ap; //result �����ʹ� a�� ���� ����Ű�� 
			rp = rp->next; //result �����͸� ��ĭ �̵��� �� 
			ap = ap->next; //a�� �������� ����ŵ�ϴ�. 
		}
		else{
			rp->next = bp; //a�� ���� �� Ŭ�� rp�� b�� ����Ű�� 
			rp = rp->next; //rp�� ��ĭ �̵��� �� 
			bp = bp->next; //b�� �������� ����ŵ�ϴ�. 
		}
	}
	
	if(ap->next == NULL){
		while(bp->next != NULL){
			rp->next = bp;
			bp = bp->next;
		}
		bp = result->tail; //a�� ���� �������� ���� b�� ���ҵ��� ��������ְ� tail���� 
	}
	else if(bp->next == NULL){
		while(ap->next != NULL){
			rp->next = ap;
			ap = ap->next;
		}
		ap = result->tail;//b�� ���� �������� ���� a�� ���ҵ��� ��������ְ� tail���� 
	}
	
	return result;
}

void print(List* lp){
	Node* temp = lp->head->next;
	while(temp->next != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void select_sort(int* arr, int len){ //�������� �ڵ��Դϴ�. 
	int i, j, temp;
	for(i=0; i<len-1; ++i){
		for(j=i+1; j<len; ++j){
			if(arr[i] > arr[j]){
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}

int main(void){
	int random, i;
	int arr[20];
	srand(time(NULL));
	
	List* a = (List*)malloc(sizeof(List));
	List* b = (List*)malloc(sizeof(List));
	List* d = (List*)malloc(sizeof(List));
	
	init_list(a);
	init_list(b);
	init_list(d);
	
	//a����Ʈ ���// 
	printf("����Ʈ a: ");
	for(i=0; i<20; ++i){ //20�� ���� �Ҵ� 
		random = rand();
		random = random%1000 + 1;
		arr[i] = random;
	}
	select_sort(arr, 20); //���� 
	for(i=0; i<20; ++i) //����Ʈ�� ������ �����Ѵ�. 
		Append(a, arr[i]);
	print(a);
	
	//b����Ʈ ���// 
	printf("����Ʈ b: ");
	for(i=0; i<20; ++i){
		random = rand();
		random = random%1000 + 1;
		arr[i] = random;
	}
	select_sort(arr, 20);
	for(i=0; i<20; ++i)
		Append(b, arr[i]);
	print(b);
	
	//�պ������Ͽ� ���// 
	printf("����Ʈ d: ");
	d= merge(a, b); //d�� a�� b�� �����Ͽ� ������ ����Ʈ�̴�. 
	print(d);
	
	return 0;
}