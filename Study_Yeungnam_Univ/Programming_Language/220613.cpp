/*
���� 1


*/

#if 0
#include <iostream>
#include <fstream>
using namespace std;

int getFileSize(const char* file) throw(char*) {
	if (file == NULL)
		throw - 1;
	ifstream fin(file);
	if (!fin)
		throw - 2;
	fin.seekg(0, ios::end);
	int length = fin.tellg();
	return length;
}

int main() {
	try {
		int n = getFileSize("C:\\Windows\\system.ini"); // ���� ũ�� 219����
		cout << "���� ũ�� = " << n << endl;
		int m = getFileSize(NULL);
		cout << "���� ũ�� = " << m << endl;
	}
	catch (int x) {
		if (x == -1)
			cout << "���� �߻� : ���ϸ��� NULL �Դϴ�." << endl;
		else if (x == -2)
			cout << "���� �߻� : ���� ���Ⱑ �����Ͽ����ϴ�." << endl;
	}
}
#endif