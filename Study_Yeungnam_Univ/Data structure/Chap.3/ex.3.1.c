#include <stdio.h>
 /* 자료형의 크기 확인하기 */
void main(){
	char c, c_array[100];
	int i, i_array[100];
	short s, s_array[100];
 	float f, f_array[100];
	long l, l_array[100];

	printf("\n char c의 size = %d \t: char c_array의 size = %4d",  	sizeof(c), sizeof(c_array));
	printf("\n int i의 size = %d \t: int i_array의 size = %4d", 	sizeof(i), sizeof(i_array));
	printf("\n short s의 size = %d \t: short s_array의 size = %4d",	sizeof(s), sizeof(s_array));
	printf("\n float f의 size = %d \t: float f_array의 size = %4d", sizeof(f), sizeof(f_array));
    	printf("\n long l의 size = %d \t: long l_array의 size = %4d", 	sizeof(l), sizeof(l_array));

 	getchar();
}
