#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

struct PERSON {
	int idx;
	int score;
	int cnt;
	int tim;
};

vector<PERSON> v;

bool cmp(PERSON a, PERSON b) {
	if (a.score == b.score) {
		if (a.cnt == b.cnt)
			return a.tim < b.tim;
		return a.cnt < b.cnt;
	}
	return a.score > b.score;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int S, C, L;
		cin >> S >> C >> L;
		v.push_back({ i, S, C, L });
	}
	sort(v.begin(), v.end(), cmp);
	cout << v[0].idx;

	return 0;
}