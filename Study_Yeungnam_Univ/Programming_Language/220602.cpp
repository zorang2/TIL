/*
12�� ������
read write�� ��� ���� ���� ������� ����ڴµ�


<�ؽ�Ʈ I/O�� ���̳ʸ� I/O�� ���� ��� ��>
�ؽ�ƮI/O��� ���̳ʸ�I/O��� ������ �����ϴ°� ���迡 ������ ������ �� �ְ���?


*/

#if 0
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* file = "C:\\Windows\\system.ini";

	ifstream fin;
	fin.open(file, ios::in | ios::binary); // ���̳ʸ� �б� ���� ���� ����
	if (!fin) {
		cout << "���Ͽ������";
			return 0;
	}

	int count = 0;
	char s[32];
	while (!fin.eof()) { //���� ������ �д´�
		fin.read(s, 32); // �ִ� 32 ����Ʈ�� �о� �迭 s�� ����
		int n = fin.gcount(); // ���� ���� ����Ʈ �� �˾Ƴ�
		cout.write(s, n);
		count += n;
	}

	cout << "���� ����Ʈ ���� " << count << endl;
	fin.close();	//�Է� ���� �ݱ�
}
#endif