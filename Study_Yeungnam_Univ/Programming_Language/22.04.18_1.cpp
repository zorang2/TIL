/*
Book ��ü�� ���� ���� ������ �ϰ����Ѵ�.

Book a("û��", 20000, 300), b("�̷�", 30000, 500);
a += 500; // å

����Լ�, �ܺ��Լ��� �� �ڵ�� �����غ���


*/

#if 0 //��� �Լ�
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price;
	int pages;
};

public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}
	void show() {
		cout << title << '' << price
	}

#endif