/*
friend�Լ�, Ŭ����
	friend�Լ� ����x

find�Լ�

�ǽ�����3 string Ŭ������ �̿��Ͽ� ~[7�� 49p]
�������� �� �Ʒ� ���� �ڵ�

������ ������ �ܴ������ ���´�.

	�Լ��ߺ��� ��ȣ�� 3����
		1.����ȯ�������Ѹ�ȣ��
		2.�����Ű����������� ��ȣ��
		3. ����Ʈ�Ű����������Ѹ�ȣ��

	c++ �Լ� �������޹�� 3����
		��ȣ�� �ּ�ȣ�� ����ȣ��

	�����޸��Ҵ�
		new, delete

*/

#if 0
#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;

	cout << "���ڿ� �Է� ";
	getline(cin, text); // �� ĭ�� �����ϴ� ���ڿ� �� ���� �Է�

	int count = 0;
	int index = 0;
	while (true) {
		index = text.find('a', index); // index���� 'a' ã��
		if (index == -1)
			break;
		count++;
		index++; // ���� ã�� �ٷ� ���� ��ġ���� ã�� ����
	}
	cout << "���� a��" << count << "�� �ֽ��ϴ�. " << endl;
}


#endif