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
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

vector<vector<char>> v(101, vector<char>(101));
vector<int> win_cnt(101, 0);

int Fight(char x, char y) {
	if ((x == 'G' && y == 'G') || (x == 'C' && y == 'C') || (x == 'P' && y == 'P'))
		return 0;
	if ((x == 'G' && y == 'C') || (x == 'C' && y == 'P') || (x == 'P' && y == 'G'))
		return 1;
	return -1;
}

bool cmp(pii a, pii b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<pii> ranking(2 * N);
	FOR(i, 1, 2 * N) {
		FOR(j, 1, M) {
			cin >> v[i][j];
		}
	}
	FOR(i, 0, 2 * N - 1) {
		ranking[i] = { i + 1, 0 };
	}
	FOR(i, 1, M) {
		for (int j = 0; j <= 2 * N - 1; j += 2) {
			int a = ranking[j].first;
			int b = ranking[j + 1].first;
			int result = Fight(v[a][i], v[b][i]);
			if (result == 1)
				ranking[j].second += 1;
			else if (result == -1)
				ranking[j + 1].second += 1;
		}
		sort(ALL(ranking), cmp);
	}
	FOR(i, 0, 2 * N - 1)
		P1(ranking[i].first);

	return 0;
}