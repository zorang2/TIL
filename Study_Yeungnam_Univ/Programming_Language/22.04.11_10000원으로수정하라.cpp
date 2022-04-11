/*
�����ؼ� 10000���� �ǰ� �϶�

*/

///������
#if 1
#include <iostream>
using namespace std;

class Person {
public:
	int money;
	void addMoney(int money) {
		this->money += money;
	}

	static int sharedMoney;//����
	static void addShared(int n) {
		sharedMoney += n;
	}
};

// static ���� ����. ���� ������ ����
int Person::sharedMoney = 10; //10���� �ʱ�ȭ

//main�Լ�
int main() {
	Person::addShared(50); //static ��� ����, ���� = 60
	//cout << Person::sharedMoney << endl;

	Person han;
	han.money = 100;
	han.sharedMoney = 200;
	Person::sharedMoney = 300;
	Person::addShared(9700);

	cout << Person::sharedMoney << "�� �Դϴ�." << endl;
}
#endif



///����
#if 0
#include <iostream>
using namespace std;

class Person {
public:
	int money;
	void addMoney(int money) {
		this->money += money;
	}

	static int sharedMoney;//����
	static void addShared(int n) {
		sharedMoney += n;
	}
};

// static ���� ����. ���� ������ ����
int Person::sharedMoney = 10; //10���� �ʱ�ȭ

//main�Լ�
int main() {
	Person::addShared(50); //static ��� ����, ����=60
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
