#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    int a = 11;
    int* p1 = &a;
    int* p2 = p1;

    printf("%p\n", &a); // �ּҺҷ����ϱ� a�ּҳ����°� �°�,
    printf("%p\n", p2); // p2�� p1�� �ּҴϱ� p1�� �ּҴ� a�� �ּҴϱ� a�ּ� �����°� �°�,
    printf("%p\n", p1); // p1�� a�� �ּҴϱ� a�ּ� �����°� �°�,
    printf("%p\n", *p2); // *p2�� �������°� ����. *�� ���𸻰� ����ϸ� ������������(�ּҿ��� ���� �����ϴ� ����)�ϱ� ���� �������ݾ�.
}