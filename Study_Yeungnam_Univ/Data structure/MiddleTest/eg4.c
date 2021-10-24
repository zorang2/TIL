#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int doWork(int num) {
    if (num == 1) return 1;
    return num * doWork(num-1);
}

int main() {
    int result = 0;
    int num = 5;
    printf("result : %d", doWork(num));
}
