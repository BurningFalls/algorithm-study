#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	string S, P;
	int total_cnt = 0;
	bool visited[10001] = { 0, };
	int cnt;
	cin >> T;
	for (int a = 0; a < T; a++) {
		total_cnt = 0;
		cin >> S >> P;
		for (int i = 0; i < S.size(); i++) {
			cnt = 0;
			if (visited[i]) continue;
			for (int j = 0; j < P.size(); j++) {
				if (S[i + j] == P[j]) {
					cnt++;
				}
				else {
					break;
				}
			}
			if (cnt == P.size()) {
				for (int j = 0; j < P.size(); j++) {
					visited[i + j] = 1;
				}
				total_cnt++;
			}
		}
		cout << total_cnt + (S.size() - total_cnt * P.size()) << "\n";
		for (int i = 0; i < S.size(); i++) {
			visited[i] = 0;
		}
	}


	return 0;
}