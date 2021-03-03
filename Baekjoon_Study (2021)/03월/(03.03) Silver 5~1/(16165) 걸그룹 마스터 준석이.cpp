#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N, M;
map<string, vector<string>> mp1;
map<string, string> mp2;

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		string team_name;
		int num;
		cin >> team_name;
		cin >> num;
		vector<string> v;
		FOR(j, 1, num) {
			string name;
			cin >> name;
			v.push_back(name);
			mp2[name] = team_name;
		}
		sort(v.begin(), v.end());
		mp1[team_name] = v;
	}
	FOR(i, 1, M) {
		string quiz;
		int kind;
		cin >> quiz >> kind;
		if (kind == 0) {
			vector<string> tmp;
			tmp = mp1[quiz];
			for (string t : tmp)
				cout << t << "\n";
		}
		else if (kind == 1) {
			cout << mp2[quiz] << "\n";
		}
	}

	return 0;
}