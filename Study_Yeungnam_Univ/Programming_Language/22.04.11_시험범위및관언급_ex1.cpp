/*
* 22-04-11
시험범위 7장까지.
책에있는 객관식 문제를 응용해서 낼거다라고하시네
코드중에서 빈칸넣어서 (중요한부분, 꼭알아야되는거) 단답식으로 적을 수 있게 그렇게 낼겁니다 람쥐

연습문제 + 체크타임 같이 공부해라

307쪽 1번, 2번 다음코드에서 틀린부분을 찾고 이유를 설명하라 느낌처럼낼꺼래 (책에서 똑같이 내진 않고)

개념설명부분 코드 보면서 공부하면 안부담스러울 것 이다...!

연습문제도있지만 중간중간에 체크타임이있고 똑같이내진못하더라도 비슷하게라도 내려고하신다네

6장은 오늘 공부한 게 끝이라는데 ㅇㅅㅇ..?
*/

#if 0
#include <iostream>
using namespace std;

class Math {
public:
	static int abs(int a) { return a > 0 ? a : -a; }
	static int max(int a, int b) { return (a > b) ? a : b; }
	static int min(int a, int b) { return (a > b) ? b : a; }
};

int main() {
	cout << Math::abs(-5) << endl;
	cout << Math::max(10, 8) << endl;
	cout << Math::min(-3, -8) << endl;
}


#endif
