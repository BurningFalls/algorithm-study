#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

typedef struct _NODE {
	int px;
	int tx;
	int cx;
} NODE;

bool cmp(NODE a, NODE b) {
	return a.cx < b.cx;
}

int main() {
	FASTIO;
	queue<pii> q;
	vector<NODE> v;
	int N, T, W, M;
	cin >> N >> T >> W;
	FOR(i, 1, N) {
		int px, tx;
		cin >> px >> tx;
		q.push({ px, tx });
	}
	cin >> M;
	FOR(i, 1, M) {
		int px, tx, cx;
		cin >> px >> tx >> cx;
		v.push_back({ px, tx, cx });
	}
	sort(v.begin(), v.end(), cmp);
	int idx = 0;
	int time = 0;
	while (time < W) {
		int px = q.front().first;
		int tx = q.front().second;
		FOR(i, 1, min(min(T, tx), W - time))
			cout << px << "\n";
		time += min(T, tx);
		tx = max(0, tx - T);
		q.pop();
		while (idx < M && v[idx].cx <= time) {
			q.push({ v[idx].px, v[idx].tx });
			idx++;
		}
		if (tx != 0)
			q.push({ px, tx });
	}


	return 0;
}