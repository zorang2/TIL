/*
수정해서 10000원이 되게 하라

*/

///수정본
#if 1
#include <iostream>
using namespace std;

class Person {
public:
	int money;
	void addMoney(int money) {
		this->money += money;
	}

	static int sharedMoney;//공금
	static void addShared(int n) {
		sharedMoney += n;
	}
};

// static 변수 생성. 전역 공간에 생성
int Person::sharedMoney = 10; //10으로 초기화

//main함수
int main() {
	Person::addShared(50); //static 멤버 접근, 공금 = 60
	//cout << Person::sharedMoney << endl;

	Person han;
	han.money = 100;
	han.sharedMoney = 200;
	Person::sharedMoney = 300;
	Person::addShared(9700);

	cout << Person::sharedMoney << "원 입니다." << endl;
}
#endif



///원본
#if 0
#include <iostream>
using namespace std;

class Person {
public:
	int money;
	void addMoney(int money) {
		this->money += money;
	}

	static int sharedMoney;//공금
	static void addShared(int n) {
		sharedMoney += n;
	}
};

// static 변수 생성. 전역 공간에 생성
int Person::sharedMoney = 10; //10으로 초기화

//main함수
int main() {
	Person::addShared(50); //static 멤버 접근, 공금=60
	cout << Person::sharedMoney << endl;

	Person han;
	han.money = 100;
	han.sharedMoney = 200;
	Person::sharedMoney = 300;
	Person::addShared(100);

	cout << han.money << ' '
		<< Person::sharedMoney << endl;
}


#endif
