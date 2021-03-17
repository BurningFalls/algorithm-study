#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

string s;
int len;
vector<char> v;
string ans = "";
bool use[7] = { 0, };
set<string> S;

void DFS(int cnt) {
	if (cnt == len) {
		S.insert(ans);
		return;
	}
	FOR(i, 0, len - 1) {
		if (use[i]) continue;
		use[i] = 1;
		ans += v[i];
		DFS(cnt + 1);
		ans.pop_back();
		use[i] = 0;
	}
}

int main() {
	FASTIO;
	cin >> s;
	len = s.size();
	FOR(i, 0, len - 1) {
		v.push_back(s[i]);
	}
	sort(v.begin(), v.end());
	DFS(0);
	bool flag = false;
	bool Find = false;
	for (auto it = S.begin(); it != S.end(); it++) {
		string tmp = (*it);
		if (flag) {
			Find = true;
			cout << (*it);
			break;
		}
		if (tmp == s)
			flag = true;
	}
	if (!Find)
		cout << 0;

	return 0;
}