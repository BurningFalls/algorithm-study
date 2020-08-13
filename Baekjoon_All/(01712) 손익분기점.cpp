#include <iostream>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	if (B >= C)
		cout << -1 << endl;
	else
		cout << A / (C - B) + 1 << endl;
	/*
	A + B * N < C * N    (N : 판매량)
	(C - B) * N > A      (C - B > 0일 때만)
	N > A / (C - B)      (C - B > 0일 때만)

	A / (C - B)는 int여서 나눗셈 후 소수점이 버려짐
	N은 나눗셈 결과(소수)보다 커야 하므로 +1
	N과 나눗셈 결과(정수)가 같다면 그것보다 1개 많아야
	이익이 발생하므로 +1
	*/
	return 0;
}