/*
12장 복습중
read write로 블록 단위 파일 입출력을 배우자는데


<텍스트 I/O와 바이너리 I/O의 실행 결과 비교>
텍스트I/O모드 바이너리I/O모드 차이점 구분하는거 시험에 나오면 구분할 수 있겠죠?


*/

#if 0
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* file = "C:\\Windows\\system.ini";

	ifstream fin;
	fin.open(file, ios::in | ios::binary); // 바이너리 읽기 모드로 파일 열기
	if (!fin) {
		cout << "파일열기오류";
			return 0;
	}

	int count = 0;
	char s[32];
	while (!fin.eof()) { //파일 끝까지 읽는다
		fin.read(s, 32); // 최대 32 바이트를 읽어 배열 s에 저장
		int n = fin.gcount(); // 실제 읽은 바이트 수 알아냄
		cout.write(s, n);
		count += n;
	}

	cout << "읽은 바이트 수는 " << count << endl;
	fin.close();	//입력 파일 닫기
}
#endif