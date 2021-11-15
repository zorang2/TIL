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

void init_list(List* lp){ //리스트를 초기화합니다. 
	lp->head = (Node*)malloc(sizeof(Node));
	lp->tail = (Node*)malloc(sizeof(Node));
	lp->head->next = lp->tail;
	lp->tail->next = NULL;
}

void Append(List* lp, element _data){ //리스트의 마지막에 노드를 삽입합니다. 
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = _data;
	newNode->next = NULL;
	
	if(lp->head->next == lp->tail){ //리스트의 원소가 없을 때 
		lp->head->next = newNode;
		newNode->next = lp->tail;
	}
	
	else{
		Node* temp = lp->head;
		while(temp->next != lp->tail){ //tail 전에서 멈추고 노드 삽입. 
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = lp->tail;
	}
}

List* merge(List* a, List* b){ //리스트 두개를 정렬하여 병합합니다. 
	
	List* result = (List*)malloc(sizeof(List)); //return할 리스트를 먼저 만들고 
	init_list(result);
	result->head->next = result->tail;
	result->tail->next = NULL;
	
	Node* ap, *bp, *rp;
	ap = a->head->next; //a 리스트를 순회할 포인터를 선언하고 
	bp = b->head->next; //b 리스트를 순회할 포인터를 선언한 후 
	rp = result->head; //return할 리스트를 만들어줄 포인터를 선언합니다. 
	
	while(ap->next != NULL && bp->next != NULL){
		if(ap->data < bp->data){ //a의 값이 b의 값보다 작으면 
			rp->next = ap; //result 포인터는 a의 값을 가리키고 
			rp = rp->next; //result 포인터를 한칸 이동한 후 
			ap = ap->next; //a는 다음값을 가리킵니다. 
		}
		else{
			rp->next = bp; //a의 값이 더 클때 rp는 b를 가리키고 
			rp = rp->next; //rp를 한칸 이동한 후 
			bp = bp->next; //b는 다음값을 가리킵니다. 
		}
	}
	
	if(ap->next == NULL){
		while(bp->next != NULL){
			rp->next = bp;
			bp = bp->next;
		}
		bp = result->tail; //a가 먼저 끝났을때 남은 b의 원소들을 연결시켜주고 tail설정 
	}
	else if(bp->next == NULL){
		while(ap->next != NULL){
			rp->next = ap;
			ap = ap->next;
		}
		ap = result->tail;//b가 먼저 끝났을때 남은 a의 원소들을 연결시켜주고 tail설정 
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

void select_sort(int* arr, int len){ //선택정렬 코드입니다. 
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
	
	//a리스트 출력// 
	printf("리스트 a: ");
	for(i=0; i<20; ++i){ //20개 랜덤 할당 
		random = rand();
		random = random%1000 + 1;
		arr[i] = random;
	}
	select_sort(arr, 20); //정렬 
	for(i=0; i<20; ++i) //리스트에 값들을 삽입한다. 
		Append(a, arr[i]);
	print(a);
	
	//b리스트 출력// 
	printf("리스트 b: ");
	for(i=0; i<20; ++i){
		random = rand();
		random = random%1000 + 1;
		arr[i] = random;
	}
	select_sort(arr, 20);
	for(i=0; i<20; ++i)
		Append(b, arr[i]);
	print(b);
	
	//합병정렬하여 출력// 
	printf("리스트 d: ");
	d= merge(a, b); //d는 a와 b를 정렬하여 병합한 리스트이다. 
	print(d);
	
	return 0;
}