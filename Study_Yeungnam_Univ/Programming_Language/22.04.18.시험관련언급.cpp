/*
friend함수, 클래스
	friend함수 남발x

find함수

실습문제3 string 클래스를 이용하여 ~[7장 49p]
사진참고 및 아래 정답 코드

시험은 객관식 단답식으로 나온다.

	함수중복의 모호성 3가지
		1.형변환으로인한모호성
		2.참조매개변수로인한 모호성
		3. 디폴트매개변수로인한모호성

	c++ 함수 인자전달방식 3가지
		값호출 주소호출 참조호출

	동적메모리할당
		new, delete

*/

#if 0
#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;

	cout << "문자열 입력 ";
	getline(cin, text); // 빈 칸을 포함하는 문자열 한 라인 입력

	int count = 0;
	int index = 0;
	while (true) {
		index = text.find('a', index); // index부터 'a' 찾기
		if (index == -1)
			break;
		count++;
		index++; // 현재 찾은 바로 다음 위치부터 찾기 위해
	}
	cout << "문자 a는" << count << "개 있습니다. " << endl;
}


#endif