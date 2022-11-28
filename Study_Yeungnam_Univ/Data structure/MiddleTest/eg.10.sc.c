#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getYear(int *year){
    *year = 2021;
}
void getMonth(int month){
    month = 12;
}


int main (){
    int year = 1900;
    int month = 10;
    printf("%d %d\n",year, month);
    getYear(&year);
    getMonth(month);
    printf("%d %d\n", year, month);

}