/*
 7*2*5와 같이 곱셈 문자열을 입력하세요
로 바꿔서 출력해보라는 교수님 지시
해결못함.
 */

#if 0

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "7*2*5와 같이 곱셈 문자열을 입력하세요." << endl;
	getline(cin, s, '\n'); //문자열 입력
	int sum = 0;
	int startIndex = 0;

	while (true) {
		int fIndex = s.find('+', startIndex);
		if (fIndex == -1) {
			string part = s.substr(startIndex);
			if (part == "") break;
			cout << part << endl;
			sum = stoi(part);
			break;
		}
		int count = fIndex - startIndex;
		string part = s.substr(startIndex, count);

		cout << part << endl;
		sum = sum * stoi(part);
		startIndex = fIndex + 1;
	}
	cout << "숫자들의 곱은 " << sum;
}

#endif