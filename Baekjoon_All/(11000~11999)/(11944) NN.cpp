#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, M;
	string s;
	int cnt = 0;
	int len;
	int i = 0;
	cin >> N >> M;
	s = to_string(N);
	len = s.size();
	while (i < N) {
		if (cnt + len >= M) {
			for (int i = 0; i < M - cnt; i++) {
				cout << s[i];
			}
			break;
		}
		cout << s;
		cnt += len;
		i++;
	}

	return 0;
}