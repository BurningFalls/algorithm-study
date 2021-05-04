#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string arr[7];

char Map[4][4];
int Num[4];

bool Do() {
	FOR(i, 1, 6) {
		int len = arr[i].size();
		if (len != 3)
			return false;
	}
	vector<int> v;
	map<string, int> mp;
	FOR(num, 1, 6) {
		if (num == Num[1] || num == Num[2] || num == Num[3]) continue;
		if (mp.count(arr[num]))
			mp[arr[num]] += 1;
		else
			mp[arr[num]] = 1;
	}
	FOR(i, 1, 3) {
		FOR(j, 1, 3) {
			Map[i][j] = arr[Num[i]][j - 1];
		}
	}
	FOR(i, 1, 3) {
		string tmp = "";
		FOR(j, 1, 3) {
			tmp += Map[j][i];
		}
		if (mp.count(tmp))
			mp[tmp] -= 1;
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if ((*it).second != 0)
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	set<string> s;
	FOR(i, 1, 6)
		cin >> arr[i];
	FOR(i, 1, 6) {
		FOR(j, 1, 6) {
			FOR(k, 1, 6) {
				if (i == j || i == k || k == j) continue;
				Num[1] = i, Num[2] = j, Num[3] = k;
				if (Do()) {
					string tmp = "";
					tmp += arr[i];
					tmp += arr[j];
					tmp += arr[k];
					s.insert(tmp);
				}
			}
		}
	}
	int len = s.size();
	if (len == 0)
		cout << 0;
	else {
		auto it = s.begin();
		string ans = (*it);
		FOR(i, 0, 8) {
			cout << ans[i];
			if (i % 3 == 2 && i != 8)
				cout << "\n";
		}
	}

	return 0;
}