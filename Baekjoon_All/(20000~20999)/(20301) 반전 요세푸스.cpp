#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	deque<int> dq;
	int N, K, M;
	cin >> N >> K >> M;
	FOR(i, 1, N) {
		dq.push_back(i);
	}
	int cnt = 1;
	int deleted = 0;
	bool flag = false;
	int size = N;
	while (size != 0) {
		if (cnt == (K - 1) % size + 1) {
			if (!flag) {
				cout << dq.front() << "\n";
				dq.pop_front();
			}
			else if (flag) {
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			size--;
			deleted++;
			cnt = 1;
			if (deleted == M) {
				flag = !flag;
				deleted = 0;
			}
		}
		else {
			if (!flag) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else if (flag) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
			cnt++;
		}
	}


	return 0;
}