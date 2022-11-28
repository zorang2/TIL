/*
* 예제 3-4 생성자에서 다른 생성자 호출 연습(위임생성자 만들기)
*/

#if 1
#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle(); //위임 생성자
	Circle(int r); //타겟 생성자
	double getArea();
};

Circle::Circle() : Circle(1) {} // 위임 생성자

Circle::Circle(int r) { //타겟 생성자
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle donut;
	double area = donut.getArea();
	cout << "donut의 면적은 " << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;
}

#endif