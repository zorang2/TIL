/*
 */

#if 1

#include <iostream>
using namespace std;

void swap(int* first, int* second);

int main()
{
	//���� 2�� ����
	int x = 10;
	int y = 20;
	//�����ϱ� ���� x�� y�� �� ���
	cout << "�����ϱ� ���� x�� y�� ��" << endl;
	cout << "x: " << x << "  " << "y: " << y << endl;
	// swap �Լ��� ȣ���ؼ� ���� x�� y ����
	swap(&x, &y);
	//�����ϱ� ���� x�� y�� �� ���
	cout << "���� ���� x�� y�� ��" << endl;
	cout << "x: " << x << "  " << "y: " << y;
	return 0;
}

void swap(int* pX, int* pY)
{
	int temp = *pX;
	*pX = *pY;
	*pY = temp;
}



#endif