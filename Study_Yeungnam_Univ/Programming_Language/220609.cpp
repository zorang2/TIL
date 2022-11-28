/* ���� 1
13��
throw - catch ��
�Ƹ� 13������ϵ�

���� 1
0~100�� ������ ������ �Է¹޾� ������ ������ ���� ����ϴ� ���α׷��� �ۼ��ϼ���.
������ 0~100���̰� �ƴ� ��� ���ܷ� ó���ϼ���.
*/

#if 0
#include <iostream>
using namespace std;

char decideGrade(int score) throw(int) {

	if (score < 0 || score > 100)
		throw score;
	if (score < 60) return 'F';
	else if (score < 70) return 'D';
	else if (score < 80) return 'C';
	else if (score < 90) return 'B';
	else return 'A';
}

int main() {
	int score;
	while (true) {
		cout << "0~100 ������ ������ �Է��ϼ��� >>";
		cin >> score;
		try {
			char c = decideGrade(score);
			cout << c << "����" << endl;
		}
		catch (int s) {
			cout << s << " : ���� �Է��� �߸��Ǿ����ϴ�." << endl;
		}
	}
}


#endif