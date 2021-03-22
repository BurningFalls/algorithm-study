#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<pair<pii, int>> v;
int minimum[10001];
int check[10001] = { 0, };

bool cmp(pair<pii, int> a, pair<pii, int> b) {
	if (a.first.first == b.first.first)
		return a.first.second > b.first.second;
	return a.first.first < b.first.first;
}

bool cmp2(pair<pii, int> a, pair<pii, int> b) {
	if (a.first.second == b.first.second)
		return a.first.first > b.first.first;
	return a.first.second < b.first.second;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int D, C;
		cin >> D >> C;
		v.push_back({ { D, C }, i });
	}
	sort(v.begin(), v.end(), cmp);
	minimum[0] = v[0].first.second;
	FOR(i, 1, N - 1) {
		minimum[i] = min(minimum[i - 1], v[i].first.second);
	}
	check[v[0].second]++;
	FOR(i, 1, N - 1) {
		if (minimum[i - 1] > v[i].first.second)
			check[v[i].second]++;
	}
	
	sort(v.begin(), v.end(), cmp2);
	minimum[0] = v[0].first.first;
	FOR(i, 1, N - 1) {
		minimum[i] = min(minimum[i - 1], v[i].first.first);
	}
	check[v[0].second]++;
	FOR(i, 1, N - 1) {
		if (minimum[i - 1] > v[i].first.first)
			check[v[i].second]++;
	}
	int cnt = 0;
	FOR(i, 1, N) {
		if (check[i] == 2)
			cnt++;
	}
	cout << cnt;

	return 0;
}