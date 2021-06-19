#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

typedef struct _INF {
	string uni_name;
	string team_name;
	int score;
	int penalty;
} INF;

vector<INF> v;

bool cmp(INF a, INF b) {
	if (a.score == b.score) {
		return a.penalty < b.penalty;
	}
	return a.score > b.score;
}

bool cmp2(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N) {
		INF tmp;
		cin >> tmp.uni_name >> tmp.team_name >> tmp.score >> tmp.penalty;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp);

	int cnt = 0;
	set<string> s;
	for (INF x : v) {
		if (s.count(x.uni_name)) continue;
		cnt++;
		s.insert(x.uni_name);
		cout << x.team_name << "\n";
		if (cnt == K)
			break;
	}

	return 0;
}