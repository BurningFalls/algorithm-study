#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

vector<string> v[11];

bool cmp(string s1, string s2) {
	if (LEN(s1) == LEN(s2))
		return s1 < s2;
	return LEN(s1) < LEN(s2);
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	while (true) {
		int num;
		string s;
		cin >> num >> s;
		if (num == 0 && s == "0")
			break;
		if (LEN(v[num]) == M) continue;
		v[num].push_back(s);
	}
	FOR(i, 1, 10) {
		sort(v[i].begin(), v[i].end(), cmp);
	}
	for (int i = 1; i <= 10; i += 2) {
		for (string x : v[i])
			cout << i << " " << x << "\n";
	}
	for (int i = 2; i <= 10; i += 2) {
		for (string x : v[i])
			cout << i << " " << x << "\n";
	}

	return 0;
}