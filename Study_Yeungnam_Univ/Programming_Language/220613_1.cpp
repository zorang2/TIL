/*
���� 2
������ ������ �Է¹޾� �������� ����ϴ� ���α׷��̴�.
�� ���α׷��� 1~9�� �ƴ� ������ �ԷµǴ� ���� �ɷ����� ���ϰ�,
Ư�� ���ڰ� �ԷµǸ� ���ѷ����� �����Եȴ�.

���蹮�� ���翡�� �ȳ�.
�����̵� �ڷῡ�� �����ؼ� ��������.
�����̵��ڷ����
�������� ���� ���� ����� ���ؼ� 6�� jpg�ø�.

���蹮����
����+�˰���(��ĭä���)


���� 8~9�������� �������� �ö��
*/

#if 1
#include <iostream>
#include <stdio.h>
#include <typeinfo>
using namespace std;

int main() {
	int n;
	while (true) {
		cout << "��� �Է� >>";
		try
		{
			cin >> n;
			if (cin.fail()) // failbit�� 1�� �µǾ� �ִ� ���, ���˿� ���� �ʴ� �Է� �߻�
				throw "������ �ƴ� �� �Է�";
			if (n <= 0 || n > 9)
				throw n;
			for (int i = 1; i <= 9; i++)
				cout << n << 'x' << i << '=' << n * i << ' ';
			cout << endl;
		}
		catch (int e){
			cout << "�߸��� �Է��Դϴ�. 1~9 ������ ������ �Է��ϼ���" << endl;
		}
		catch (const char* s) {
			cout << "�Է� ������ �߻��Ͽ� �� �̻� �Էµ��� �ʽ��ϴ�. ���α׷��� �����մϴ�." << endl;
			return 0;
		}
		cout << endl;
	}
}



#endif


// ���� § �ڵ�
#if 0
#include <iostream>
#include <stdio.h>
#include <typeinfo>
using namespace std;

int main() {
	int n;
	while (true) {
		cout << "��� �Է� >>";
		cin >> n;

		try
		{

		}
		catch (int n)
		{
			if (n >= 1 && n <= 9)
				for (int i = 1; i <= 9; i++)
					cout << n << 'x' << i << '=' << n * i << ' ';
			else if (n < 1 && n>9)
				cout << "�߸��� �Է��Դϴ�. 1~9������ ������ �Է��ϼ���";
			else if (typeid(n) != ) {
				cout << "�Է� ������ �߻��Ͽ� ���̻� �Էµ��� �ʽ��ϴ�. ���α׷��� �����մϴ�.";
				return 0;
			}
		}
		cout << endl;
	}
}



#endif