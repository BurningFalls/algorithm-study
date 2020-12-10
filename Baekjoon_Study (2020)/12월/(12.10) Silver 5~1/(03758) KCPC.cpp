#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

struct Team {
	int idx = 0;
	int score[101] = { 0, };
	int cnt = 0;
	int last = 0;
};

Team arr[101];

bool cmp(Team a, Team b) {
	int a_sum = 0;
	int b_sum = 0;
	FOR(i, 1, 100) {
		a_sum += a.score[i];
		b_sum += b.score[i];
	}

	if (a_sum == b_sum) {
		if (a.cnt == b.cnt)
			return a.last < b.last;
		return a.cnt < b.cnt;
	}
	return a_sum > b_sum;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		FOR(i, 1, 100)
			arr[i] = {};
		FOR(i, 1, 100)
			arr[i].idx = i;
		int N, K, t, M;
		cin >> N >> K >> t >> M;
		FOR(i, 1, M) {
			int I, J, S;
			cin >> I >> J >> S;
			arr[I].score[J] = max(arr[I].score[J], S);
			arr[I].cnt++;
			arr[I].last = i;
		}
		sort(arr + 1, arr + N + 1, cmp);
		FOR(i, 1, N) {
			if (arr[i].idx == t) {
				cout << i << "\n";
				break;
			}
		}
	}

	return 0;
}