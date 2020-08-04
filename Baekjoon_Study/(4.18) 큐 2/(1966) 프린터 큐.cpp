#include <iostream>
#include <queue>
using namespace std;

int main() {
	int T;
	int N, M;
	queue<pair<int, int>> q;
	int pry;
	int priority[10];
	int maximum = 0;
	int cnt;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cnt = 0;
		for (int i = 1; i <= 9; i++) {
			priority[i] = 0;
		}
		while (!q.empty()) q.pop();
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> pry;
			priority[pry]++;
			q.push(make_pair(pry, i));
		}
		for (int i = 9; i >= 1; i--) {
			if (priority[i] != 0) {
				maximum = i;
				break;
			}
		}
		while (!q.empty()) {
			if (q.front().first == maximum) {
				cnt++;
				if (q.front().second == M) {
					cout << cnt << "\n";
					break;
				}
				priority[q.front().first]--;
				for (int i = q.front().first; i >= 1; i--) {
					if (priority[i] != 0) {
						maximum = i;
						break;
					}
				}
				q.pop();
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
	}


	return 0;
}