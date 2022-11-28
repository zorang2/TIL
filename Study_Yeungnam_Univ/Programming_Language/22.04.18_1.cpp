/*
Book 객체에 대해 다음 연산을 하고자한다.

Book a("청춘", 20000, 300), b("미래", 30000, 500);
a += 500; // 책

멤버함수, 외부함수로 두 코드로 구현해봐라


*/

#if 0 //멤버 함수
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