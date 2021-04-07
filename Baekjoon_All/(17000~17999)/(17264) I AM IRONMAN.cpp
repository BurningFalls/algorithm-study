#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

map<string, char> mp;
int score = 0;
int W, L, G;

void Calc(string name) {
	if (!mp.count(name)) {
		score -= L;
	}
	else {
		if (mp[name] == 'W') {
			score += W;
		}
		else if (mp[name] == 'L') {
			score -= L;
		}
	}
	if (score < 0)
		score = 0;
}

int main() {
	FASTIO;
	int N, P;
	cin >> N >> P;
	cin >> W >> L >> G;
	FOR(i, 1, P) {
		string name;
		char kind;
		cin >> name >> kind;
		mp[name] = kind;
	}
	bool flag = false;
	FOR(i, 1, N) {
		string name;
		cin >> name;
		Calc(name);
		if (score >= G)
			flag = true;
	}
	cout << (flag ? "I AM NOT IRONMAN!!" : "I AM IRONMAN!!");

	return 0;
}