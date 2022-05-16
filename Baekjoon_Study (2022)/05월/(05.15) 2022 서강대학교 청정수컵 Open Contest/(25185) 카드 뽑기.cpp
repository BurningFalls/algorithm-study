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

bool Check(vector<string> v) {
	vector<int> card[3];
	FOR(i, 0, 3) {
		if (v[i][1] == 'm') {
			card[0].push_back(v[i][0] - '0');
		}
		else if (v[i][1] == 'p') {
			card[1].push_back(v[i][0] - '0');
		}
		else if (v[i][1] == 's') {
			card[2].push_back(v[i][0] - '0');
		}
	}
	FOR(i, 0, 2) {
		sort(ALL(card[i]));
		if (LEN(card[i]) == 3) {
			if (card[i][0] + 1 == card[i][1] && card[i][1] + 1 == card[i][2]) {
				return true;
			}
			if (card[i][0] == card[i][1] && card[i][1] == card[i][2]) {
				return true;
			}
		}
		else if (LEN(card[i]) == 4) {
			if (card[i][0] + 1 == card[i][1] && card[i][1] + 1 == card[i][2]) {
				return true;
			}
			if (card[i][0] + 1 == card[i][1] && card[i][1] + 1 == card[i][3]) {
				return true;
			}
			if (card[i][0] + 1 == card[i][2] && card[i][2] + 1 == card[i][3]) {
				return true;
			}
			if (card[i][1] + 1 == card[i][2] && card[i][2] + 1 == card[i][3]) {
				return true;
			}
			if (card[i][0] == card[i][1] && card[i][1] == card[i][2]) {
				return true;
			}
			if (card[i][1] == card[i][2] && card[i][2] == card[i][3]) {
				return true;
			}
		}
	}

	sort(ALL(v));
	if (v[0] == v[1] && v[2] == v[3]) {
		return true;
	}
	return false;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		vector<string> v(4);
		FOR(i, 0, 3) {
			cin >> v[i];
		}
		cout << (Check(v) ? ":)" : ":(") << "\n";
	}

	return 0;
}