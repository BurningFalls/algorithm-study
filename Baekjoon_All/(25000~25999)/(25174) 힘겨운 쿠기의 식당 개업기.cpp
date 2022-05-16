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

bool compare1(pair<pii, int> a, pair<pii, int> b) {
	return a.first.first < b.first.first;
}

bool compare2(pair<pii, int> a, pair<pii, int> b) {
	return a.first.second < b.first.second;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<pair<pii, int>> v(N);
	vector<pair<pii, int>> ch_v(N);
	int total_sum = 0;

	FOR(i, 0, N - 1) {
		int X, Y, Z;
		cin >> X >> Y >> Z;
		v[i] = { {X, Y}, Z };
		total_sum += Z;
	}
	int endx = 0, endy = 0;
	sort(ALL(v), compare1);
	ch_v[0].first.first = 0;
	FOR(i, 1, N - 1) {
		if (v[i].first.first == v[i - 1].first.first) {
			ch_v[i].first.first = ch_v[i - 1].first.first;
		}
		else if (v[i].first.first != v[i - 1].first.first) {
			ch_v[i].first.first = ch_v[i - 1].first.first + 1;
		}
		endx = ch_v[i].first.first;
	}
	FOR(i, 0, N - 1) {
		v[i].first.first = ch_v[i].first.first;
	}
	sort(ALL(v), compare2);
	ch_v[0].first.second = 0;
	FOR(i, 1, N - 1) {
		if (v[i].first.second == v[i - 1].first.second) {
			ch_v[i].first.second = ch_v[i - 1].first.second;
		}
		else if (v[i].first.second != v[i - 1].first.second) {
			ch_v[i].first.second = ch_v[i - 1].first.second + 1;
		}
		endy = ch_v[i].first.second;
	}
	FOR(i, 0, N - 1) {
		v[i].first.second = ch_v[i].first.second;
	}

	vector<vector<int>> value(endx + 1, vector<int>(endy + 1));
	vector<vector<int>> Sum(endx + 1, vector<int>(endy + 1, 0));
	FOR(i, 0, N - 1) {
		value[v[i].first.first][v[i].first.second] = v[i].second;
	}
	Sum[0][0] = value[0][0];
	FOR(i, 1, endx) {
		Sum[i][0] = Sum[i - 1][0] + value[i][0];
	}
	FOR(i, 1, endy) {
		Sum[0][i] = Sum[0][i - 1] + value[0][i];
	}
	FOR(i, 1, endx) {
		FOR(j, 1, endy) {
			Sum[i][j] = Sum[i][j - 1] + Sum[i - 1][j] - Sum[i - 1][j - 1] + value[i][j];
		}
	}

	int mini = total_sum;
	FOR(i, 0, endx) {
		FOR(j, 0, endy) {
			int one = Sum[i][endy] - Sum[i][j];
			int two = Sum[i][j];
			int three = Sum[endx][j] - Sum[i][j];
			int four = Sum[endx][endy] - one - two - three;
			mini = min(mini, max({ one, two, three, four }) - min({ one, two, three, four }));
		}
	}
	cout << mini;

	return 0;
}