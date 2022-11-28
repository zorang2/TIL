/*
������ ��Ʈ�� ���¸� �˻��Ҷ� ��ɾ� ���
showStreamState(fin)


<���� ����(random access)�� ���� ������>

<��� ��ġ�� ���� ������ �ű��>
ios::beg <<<<< begin����. ���� ����
ios::cur <<<<< current����. ���� ����
ios::end <<<<< ������ ����


*** ���� 2 ***
�ؽ�Ʈ �����̵� ���̳ʸ� �����̵� ���� ������ ����Ʈ ������(���� ������ �ƴԿ� ����)
�Ųٷ� �纻�� �����ϴ� ���α׷��� �ۼ��ϼ���. c:\windows\system.ini������ ���������ϰ�
c:\temp\system.txt.���Ϸ� ����

*/

#if 1
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("c:\\windows\\system.ini", ios::in | ios::binary);
	if (!fin) {
		cout << "c:\\windows\\system.ini ���� ����";
		return 0;
	}
	ofstream fout("C:\\Temp\\system.txt", ios::out | ios::binary);
	if (!fout) {
		cout << "c:\\temp\\system.txt ���� ����";
		return 0;
	}



	// ���� ũ�� �˾Ƴ���
	fin.seekg(0, ios::end);
	int fileSize = fin.tellg();
	fin.seekg(0, ios::beg);


	// �ؽ�Ʈ ������ �Ųٷ� ���
	for (int i = 0; i < fileSize; i++) {
		fin.seekg(fileSize - 1 - i, ios::beg);
		int ch = fin.get();
		fout.put(ch);
	}

	cout << "���� �Ϸ�" << endl;

	fin.close();
	fout.close();




/*
	//���� ���� ����
	int copyUnit = fileSize / 10;
	char* buf = new char[copyUnit]; //�޸��Ҵ�
	cout << "���� ����..." << endl;
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
	cout << fileSize << "Byte ���� �Ϸ�" << endl;

	
	// �ؽ�Ʈ ������ �Ųٷ� ���
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

