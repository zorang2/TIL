/*
파일의 스트림 상태를 검사할때 명령어 기억
showStreamState(fin)


<임의 접근(random access)과 파일 포인터>

<상대 위치로 파일 포인터 옮기기>
ios::beg <<<<< begin약자. 시작 기준
ios::cur <<<<< current약자. 현재 기준
ios::end <<<<< 마지막 기준


*** 과제 2 ***
텍스트 파일이든 바이너리 파일이든 원본 파일을 바이트 단위로(문자 단위가 아님에 유의)
거꾸로 사본에 저장하는 프로그램을 작성하세요. c:\windows\system.ini파일을 원본으로하고
c:\temp\system.txt.파일로 저장

*/

#if 1
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("c:\\windows\\system.ini", ios::in | ios::binary);
	if (!fin) {
		cout << "c:\\windows\\system.ini 열기 오류";
		return 0;
	}
	ofstream fout("C:\\Temp\\system.txt", ios::out | ios::binary);
	if (!fout) {
		cout << "c:\\temp\\system.txt 열기 오류";
		return 0;
	}



	// 파일 크기 알아내기
	fin.seekg(0, ios::end);
	int fileSize = fin.tellg();
	fin.seekg(0, ios::beg);


	// 텍스트 파일을 거꾸로 출력
	for (int i = 0; i < fileSize; i++) {
		fin.seekg(fileSize - 1 - i, ios::beg);
		int ch = fin.get();
		fout.put(ch);
	}

	cout << "복사 완료" << endl;

	fin.close();
	fout.close();




/*
	//복사 단위 결정
	int copyUnit = fileSize / 10;
	char* buf = new char[copyUnit]; //메모리할당
	cout << "복사 시작..." << endl;
	for (int i = 0; i < 10; i++) {
		fin.read(buf, copyUnit);
		int real = fin.gcount();
		fout.write(buf, real);
		cout << '.';
		cout << real << "Byte ";
		cout << (i + 1) * 10 << '%' << endl;
		if (real < copyUnit)
			break;
	}
	cout << fileSize << "Byte 복사 완료" << endl;

	
	// 텍스트 파일을 거꾸로 출력
	for (int i = 0; i < fileSize; i++) {
		fin.seekg(fileSize - 1 - i, ios::beg);
		int ch = fin.get();
		fout.put(ch);
	}

	delete[] buf;
	fin.close();
	fout.close();
*/
	

}
#endif

