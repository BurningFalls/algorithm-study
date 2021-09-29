#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

priority_queue<pii> pq;
vector<pii> ans_v;

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		while (!pq.empty())
			pq.pop();
		ans_v.clear();
		int N;
		cin >> N;
		FOR(i, 1, N) {
			int num;
			cin >> num;
			if (num == 0) continue;
			pq.push({ num, i });
		}
		while (pq.size() >= 2) {
			pii a = pq.top();
			pq.pop();
			pii b = pq.top();
			pq.pop();
			ans_v.push_back({ a.second, b.second });
			if (--a.first != 0)
				pq.push(a);
			if (--b.first != 0)
				pq.push(b);
		}
		cout << LEN(ans_v) << "\n";
		for (pii x : ans_v)
			cout << x.first << " " << x.second << "\n";
	}

	return 0;
}