#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N;
deque<char> dq;

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		dq.clear();
		cin >> N;
		char x;
		FOR(i, 1, N) {
			cin >> x;
			if (i == 1) {
				dq.push_front(x);
				continue;
			}
			if (dq.front() >= x)
				dq.push_front(x);
			else
				dq.push_back(x);
		}
		int len = dq.size();
		FOR(i, 0, len - 1)
			cout << dq[i];
		cout << "\n";
	}


	return 0;
}