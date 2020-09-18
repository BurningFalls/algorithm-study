#include <iostream>
using namespace std;

int main() {
	int K;
	int P, M;
	int num;
	int cnt = 0;
	bool seat[501] = { 0, };
	cin >> K;
	for (int a = 0; a < K; a++) {
		for (int i = 0; i <= 500; i++)
			seat[i] = 0;
		cnt = 0;
		cin >> P >> M;
		for (int i = 0; i < P; i++) {
			cin >> num;
			if (seat[num] == 0)
				seat[num] = 1;
			else
				cnt++;
		}
		cout << cnt << "\n";
	}


	return 0;
}