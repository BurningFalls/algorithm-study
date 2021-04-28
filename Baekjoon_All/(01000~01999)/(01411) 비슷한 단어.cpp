#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string arr[101];

bool Check(string str1, string str2) {
	if (str1 == "ab" && str2 == "cd")
		int a = 1;
	int len1 = str1.size();
	int len2 = str2.size();
	if (len1 != len2)
		return false;
	bool visited[51] = { 0, };
	FOR(i, 0, len1 - 1) {
		if (visited[i]) continue;
		vector<int> v;
		char x = str1[i];
		v.push_back(i);
		visited[i] = 1;
		FOR(j, i + 1, len1 - 1) {
			if (str1[j] == x) {
				v.push_back(j);
				visited[j] = 1;
			}
		}
		if (v.empty()) continue;
		char y = str2[v[0]];
		int vlen = v.size();
		FOR(j, 0, vlen - 1) {
			if (str2[v[j]] != y)
				return false;
		}
	}
	return true;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	int ans = 0;
	FOR(i, 1, N) {
		FOR(j, i + 1, N) {
			if (Check(arr[i], arr[j]) && Check(arr[j], arr[i])) {
				ans++;
			}
		}
	}
	cout << ans;

	return 0;
}