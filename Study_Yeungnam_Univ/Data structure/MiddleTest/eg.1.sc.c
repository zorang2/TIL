#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int a = 10;
    int *p1 = &a;
    int *p2 = &p1;

    printf("%p\n", &a);
    printf("%p\n", p1);
    printf("%p\n", p2);
    printf("%p\n", *p2);
}