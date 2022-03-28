/*
this부터 시작 22.03.28
오늘 4장 끝내는게 목표
예제 4-13
*/


#if 0
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;

	cout << "문자열을 입력하세요(한글안됨) " << endl;
	getline(cin, s, '\n'); //문자열 입력
	int len = s.length(); //문자열의 길이

	for (int i = 0; i < len; i++) {
		string first = s.substr(0, 1); // 맨 앞의 문자 1개를 문자열로
		string sub = s.substr(1, len - 1); // 나머지 문자들을 문자열로
		s = sub + first; // 두 문자열을 연결하여 새로운 문자열로 만듦
		cout << s << endl;
	}
}
#endif
