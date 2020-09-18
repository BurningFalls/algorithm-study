#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	int h_max = 0;
	int a_max = 0;
	int num;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num;
		h_max = max(h_max, num);
	}
	for (int i = 0; i < M; i++) {
		cin >> num;
		a_max = max(a_max, num);
	}
	cout << h_max + a_max;

	return 0;
}