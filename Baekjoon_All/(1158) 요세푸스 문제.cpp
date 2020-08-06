#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> q1, q2;
	int N, K;
	int one_flag = true;
	int two_flag = false;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		q1.push(i);
	}
	cout << "<";
	for (int i = 1; i <= N * K; i++) {
		if (q1.empty()) {
			one_flag = false;
			two_flag = true;
		}
		if (q2.empty()) {
			one_flag = true;
			two_flag = false;
		}
		if (i % K == 0) {
			if (one_flag) {
				cout << q1.front();
				if (i != N * K)
					cout << ", ";
				q1.pop();
			}
			else if (two_flag) {
				cout << q2.front();
				if (i != N * K)
					cout << ", ";
				q2.pop();
			}
		}
		else {
			if (one_flag) {
				q2.push(q1.front());
				q1.pop();
			}
			else if (two_flag) {
				q1.push(q2.front());
				q2.pop();
			}
		}
	}
	cout << ">";

	return 0;
}