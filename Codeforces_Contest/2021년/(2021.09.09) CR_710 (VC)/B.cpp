#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		string s;
		cin >> s;
		int left = 0;
		int right = N - 1;
		while (s[left] == '.')
			left++;
		while (s[right] == '.')
			right--;
		if (left == right) {
			cout << "1\n";
			continue;
		}
		int ans = 2;
		queue<int> q;
		int cnt = 0;
		FOR(i, left + 1, right) {
			if (s[i] == '.')
				cnt++;
			else if (s[i] == '*') {
				q.push(cnt + 1);
				cnt = 0;
			}
		}
		int sum = 0;
		while (!q.empty()) {
			int node = q.front();
			if (sum + node > K) {
				ans++;
				sum = 0;
			}
			else {
				sum += node;
				q.pop();
			}
		}
		cout << ans << "\n";
	}


	return 0;
}