/*
* ���� 3-4 �����ڿ��� �ٸ� ������ ȣ�� ����(���ӻ����� �����)
*/

#if 1
#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle(); //���� ������
	Circle(int r); //Ÿ�� ������
	double getArea();
};

Circle::Circle() : Circle(1) {} // ���� ������

Circle::Circle(int r) { //Ÿ�� ������
	radius = r;
	cout << "������ " << radius << " �� ����" << endl;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle donut;
	double area = donut.getArea();
	cout << "donut�� ������ " << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza ������ " << area << endl;
}

#endif