#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	int T;
	string P;
	int N;
	deque<int> dq;
	char sign;
	int xn;
	bool is_front;
	bool is_error;
	cin >> T;
	for (int a = 0; a < T; a++) {
		dq.clear();
		is_front = true;
		is_error = false;
		cin >> P;
		cin >> N;
		cin >> sign;
		if (N == 0) {
			cin >> sign;
		}
		else {
			for (int i = 0; i < N; i++) {
				cin >> xn;
				dq.push_back(xn);
				cin >> sign;
			}
		}
		for (int i = 0; i < P.size(); i++) {
			if (P[i] == 'R') {
				is_front = !is_front;
			}
			else if (P[i] == 'D') {
				if (dq.empty()) {
					is_error = true;
					break;
				}
				else {
					if (is_front) {
						dq.pop_front();
					}
					else {
						dq.pop_back();
					}
				}
			}
		}
		if (is_error) {
			cout << "error\n";
		}
		else {
			cout << "[";
			if (is_front) {
				for (int i = 0; i < dq.size(); i++) {
					cout << dq[i];
					if (i != dq.size() - 1)
						cout << ",";
				}
			}
			else {
				for (int i = dq.size() - 1; i >= 0; i--) {
					cout << dq[i];
					if (i != 0)
						cout << ",";
				}
			}
			cout << "]\n";
		}
	}


	return 0;
}