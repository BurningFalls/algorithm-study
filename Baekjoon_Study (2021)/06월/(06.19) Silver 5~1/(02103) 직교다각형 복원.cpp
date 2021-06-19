#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool cmp1(pii a, pii b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

bool cmp2(pii a, pii b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<pii> v;
	FOR(i, 1, N) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	int sum = 0;
	sort(v.begin(), v.end(), cmp1);
	for (int i = 0; i < N; i += 2) {
		sum += v[i + 1].second - v[i].second;
	}
	sort(v.begin(), v.end(), cmp2);
	for (int i = 0; i < N; i += 2) {
		sum += v[i + 1].first - v[i].first;
	}
	cout << sum;

	return 0;
}