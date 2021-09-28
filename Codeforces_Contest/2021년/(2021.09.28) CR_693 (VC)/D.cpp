#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

priority_queue<ll> even, odd;

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		FOR(i, 1, N) {
			ll num;
			cin >> num;
			if (num % 2 == 1)
				odd.push(num);
			else if (num % 2 == 0)
				even.push(num);
		}
		odd.push(0);
		even.push(0);
		int cnt = 0;
		ll score1 = 0, score2 = 0;
		while (cnt < N) {
			if (cnt % 2 == 0) {
				if (odd.top() > even.top()) {
					odd.pop();
				}
				else if (odd.top() < even.top()) {
					score1 += even.top();
					even.pop();
				}
			}
			else if (cnt % 2 == 1) {
				if (odd.top() > even.top()) {
					score2 += odd.top();
					odd.pop();
				}
				else if (odd.top() < even.top()) {
					even.pop();
				}
			}
			cnt++;
		}
		if (score1 > score2)
			cout << "Alice";
		else if (score1 == score2)
			cout << "Tie";
		else if (score1 < score2)
			cout << "Bob";
		cout << "\n";
	}

	return 0;
}