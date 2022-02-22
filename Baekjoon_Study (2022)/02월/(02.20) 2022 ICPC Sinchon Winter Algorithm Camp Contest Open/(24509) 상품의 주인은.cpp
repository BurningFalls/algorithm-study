#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

bool cmp(pii a, pii b) {
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

void Print(PQ<pii, vector<pii>, bool(*)(pii, pii)>&pq, vector<bool>& ch) {
	while (!pq.empty() && ch[pq.top().second]) {
		pq.pop();
	}
	int idx = pq.top().second;
	ch[idx] = 1;
	cout << idx << " ";
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	PQ<pii, vector<pii>, bool(*)(pii, pii)> kor(cmp), eng(cmp), math(cmp), sci(cmp);
	vector<bool> check(N + 1, 0);
	FOR(i, 1, N) {
		int idx, a, b, c, d;
		cin >> idx >> a >> b >> c >> d;
		kor.push({ a, idx });
		eng.push({ b, idx });
		math.push({ c, idx });
		sci.push({ d, idx });
	}
	Print(kor, check);
	Print(eng, check);
	Print(math, check);
	Print(sci, check);

	return 0;
}