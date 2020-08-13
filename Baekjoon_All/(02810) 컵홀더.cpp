#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int N;
	string s;
	int cnt = 1;
	int l_cnt = 0;
	cin >> N;
	cin >> s;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'S') {
			cnt++;
		}
		else if (s[i] == 'L') {
			l_cnt++;
			if (l_cnt == 2) {
				l_cnt = 0;
				cnt++;
			}
		}
	}
	cout << min(cnt, N);

	return 0;
}