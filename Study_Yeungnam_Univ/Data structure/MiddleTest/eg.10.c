#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    int a = 11;
    int* p1 = &a;
    int* p2 = p1;

    printf("%p\n", &a); // 주소불렀으니까 a주소나오는게 맞고,
    printf("%p\n", p2); // p2는 p1의 주소니까 p1의 주소는 a의 주소니까 a주소 나오는게 맞고,
    printf("%p\n", p1); // p1은 a의 주소니까 a주소 나오는게 맞고,
    printf("%p\n", *p2); // *p2는 값나오는게 맞지. *를 선언말고 사용하면 역참조연산자(주소에서 값에 접근하는 역할)니까 값을 리턴하잖아.
}