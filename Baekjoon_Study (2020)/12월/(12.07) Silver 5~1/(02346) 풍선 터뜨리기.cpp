#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

deque<pii> dq;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		dq.push_back({ i, num });
	}
	while (true) {
		int idx = dq.front().first;
		int x = dq.front().second;
		dq.pop_front();
		cout << idx << " ";
		if (dq.empty())
			break;
		if (x > 0) {
			FOR(i, 1, x - 1) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else if (x < 0) {
			FOR(i, 1, -x) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}

	return 0;
}