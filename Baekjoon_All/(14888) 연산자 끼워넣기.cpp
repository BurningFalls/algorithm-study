#include <iostream>
#include <algorithm>
using namespace std;

int A[12];
int N;
int oper_cnt[4];
int result;
int maximum = -1000000001;
int minimum = 1000000001;

void cal(int oper, int num) {
	if (oper == 0)
		result += num;
	else if (oper == 1)
		result -= num;
	else if (oper == 2)
		result *= num;
	else if (oper == 3)
		result /= num;
}

void DFS(int ans, int cnt) {
	if (cnt == N - 1) {
		maximum = max(maximum, result);
		minimum = min(minimum, result);
		return;
	}

	// i=0->'+' | i=1->'-' | i=2->'*' | i=3->'/'
	for (int i = 0; i < 4; i++) {
		if (oper_cnt[i] == 0) continue;
		oper_cnt[i]--;
		cal(i, A[cnt + 1]);
		DFS(result, cnt + 1);
		result = ans;
		oper_cnt[i]++;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper_cnt[i];
	}

	result = A[0];
	DFS(result, 0);

	cout << maximum << "\n" << minimum;

	return 0;
}