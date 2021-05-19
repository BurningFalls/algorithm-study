#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int score[101];
vector<pii> v;

bool cmp(pii a, pii b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, N) {
		cin >> score[i];
	}
	FOR(i, 1, M) {
		int num;
		cin >> num;
		int sum = 0;
		FOR(j, 1, N) {
			char x;
			cin >> x;
			if (x == 'O')
				sum += score[j];
		}
		v.push_back({ num, sum });
	}
	sort(v.begin(), v.end(), cmp);
	cout << v[0].first << " " << v[0].second;

	return 0;
}