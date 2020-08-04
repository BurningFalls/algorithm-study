#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int A, B, V;
	cin >> A >> B >> V;
	int temp = (V - A) / (A - B);
	if ((V - A) % (A - B) == 0) {
		cout << temp + 1 << endl;
	}
	else {
		cout << temp + 2 << endl;
	}

	/*
	한 번에 A미터만큼 올라갈수 있으므로 그 전날
	(V-A)미터 이상의 높이에 있다면, 그날 밤을 계산하지 않고
	바로 끝낼 수 있다. (반대로 그 높이 미만에 있다면 절대로
	불가능 하므로 밤에 미끄러지는 것까지 같이 계산해도 무방함)

	(V-A)미터 전까지 하루에 (A-B)미터 만큼 상승
	(V-A)미터에 도달하기까지 직전까지 걸리는 날 수(temp)
		= (V - A) / (A - B) (int)

	정확히 (V-A)미터에 도달했다면, ((V-A) % (A - B) == 0이라면)
	낮에 한 번에 올라가면 끝이므로 temp + 1
	하루만 더 낮밤을 지내면 (V-A)미터 이상에 도달한다면, (else)
	해당 하루에 한 번 더 낮에 올라가면 끝이므로 temp + 2
	*/

	return 0;
}