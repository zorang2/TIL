/*
과제 2
다음은 정수를 입력받아 구구단을 출력하는 프로그램이다.
이 프로그램은 1~9가 아닌 정수가 입력되는 것을 걸러내지 못하고,
특히 문자가 입력되면 무한루프에 빠지게된다.

시험문제 교재에서 안냄.
슬라이드 자료에서 응용해서 문제나감.
슬라이드자료봐라
요점정리 교재 없는 사람을 위해서 6개 jpg올림.

시험문제는
개념+알고리즘(빈칸채우기)


당일 8~9시정도에 시험점수 올라옴
*/

#if 1
#include <iostream>
#include <stdio.h>
#include <typeinfo>
using namespace std;

int main() {
	int n;
	while (true) {
		cout << "양수 입력 >>";
		try
		{
			cin >> n;
			if (cin.fail()) // failbit이 1로 셋되어 있는 경우, 포맷에 맞지 않는 입력 발생
				throw "정수가 아닌 값 입력";
			if (n <= 0 || n > 9)
				throw n;
			for (int i = 1; i <= 9; i++)
				cout << n << 'x' << i << '=' << n * i << ' ';
			cout << endl;
		}
		catch (int e){
			cout << "잘못된 입력입니다. 1~9 사이의 정수만 입력하세요" << endl;
		}
		catch (const char* s) {
			cout << "입력 오류가 발생하여 더 이상 입력되지 않습니다. 프로그램을 종료합니다." << endl;
			return 0;
		}
		cout << endl;
	}
}



#endif


// 내가 짠 코드
#if 0
#include <iostream>
#include <stdio.h>
#include <typeinfo>
using namespace std;

int main() {
	int n;
	while (true) {
		cout << "양수 입력 >>";
		cin >> n;

		try
		{

		}
		catch (int n)
		{
			if (n >= 1 && n <= 9)
				for (int i = 1; i <= 9; i++)
					cout << n << 'x' << i << '=' << n * i << ' ';
			else if (n < 1 && n>9)
				cout << "잘못된 입력입니다. 1~9사이의 정수만 입력하세요";
			else if (typeid(n) != ) {
				cout << "입력 오류가 발생하여 더이상 입력되지 않습니다. 프로그램을 종료합니다.";
				return 0;
			}
		}
		cout << endl;
	}
}



#endif