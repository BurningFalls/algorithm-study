#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

map<char, int> mp;

bool compare(string a, string b) {
	char cha = a[0];
	char chb = b[0];
	int inta = stoi(a.substr(1, LEN(a) - 1));
	int intb = stoi(b.substr(1, LEN(b) - 1));
	if (cha == chb) {
		return inta > intb;
	}
	else {
		return mp[cha] < mp[chb];
	}
}

int main() {
	FASTIO;
	mp['B'] = 1;
	mp['S'] = 2;
	mp['G'] = 3;
	mp['P'] = 4;
	mp['D'] = 5;
	int N;
	cin >> N;
	vector<string> v(N);
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}

	vector<string> v2(v);
	sort(ALL(v2), compare);

	vector<string> ans;
	FOR(i, 0, N - 1) {
		if (v[i] != v2[i]) {
			ans.push_back(v2[i]);
		}
	}
	sort(ALL(ans), compare);

	if (ans.empty()) {
		cout << "OK";
	}
	else {
		cout << "KO\n";
		FOR(i, 0, LEN(ans) - 1) {
			cout << ans[i] << " ";
		}
	}

	return 0;
}