/* ����2
0~9 ������ ������ Ű���忡�� �Է¹޾� �����ϴ� get()�Լ��� ������ ������ ����.

int get() throw(char *c);

get()
*/

#if 1
#include <iostream>
using namespace std;

int get() throw(char*) {
	int n;
	cout << "0~9 ������ ���� �Է� >> ";
	cin >> n;
	if (n >= 0 && n <= 9)
		return n;
	else
		throw "input fault";
}

int main() {
	int n, m;
	while (true) {
		try {
			n = get();
			m = get();
			cout << n << 'x' << m << '=' << n * m << endl;
		}
		catch (const char* s) {
			cout << s << "���� �߻�, ����� �� ����" << endl;
		}
	}
}


#endif