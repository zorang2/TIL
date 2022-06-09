/* 과제2
0~9 사이의 정수를 키보드에서 입력받아 리턴하는 get()함수의 원형은 다음과 같다.

int get() throw(char *c);

get()
*/

#if 1
#include <iostream>
using namespace std;

int get() throw(char*) {
	int n;
	cout << "0~9 사이의 정수 입력 >> ";
	cin >> n;
	if (n >= 0 && n <= 9)
		return n;
	else
		throw "input fault";
}

int main() {
	int n, m;
	while (true) {
		try {
			n = get();
			m = get();
			cout << n << 'x' << m << '=' << n * m << endl;
		}
		catch (const char* s) {
			cout << s << "예외 발생, 계싼할 수 없음" << endl;
		}
	}
}


#endif