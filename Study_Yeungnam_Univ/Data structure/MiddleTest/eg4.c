#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int doWork(int num) {
    if (num == 1 || num == 0) return 1;
    return num * doWork(num-2);
}

int main() {
    int num = 6;
    printf("result : %d", doWork(num));
}
