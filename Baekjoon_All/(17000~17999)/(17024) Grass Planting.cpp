#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int cnt[100001] = { 0, };

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N - 1) {
		int a, b;
		cin >> a >> b;
		cnt[a]++;
		cnt[b]++;
	}
	int max_cnt = 0;
	FOR(i, 1, N) {
		max_cnt = max(max_cnt, cnt[i]);
	}
	cout << max_cnt + 1;


	return 0;
}