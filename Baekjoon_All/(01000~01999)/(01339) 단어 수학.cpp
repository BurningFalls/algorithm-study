#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

map<char, int> mp;
vector<int> v;
int num[10] = { 0, };
bool visited[10] = { 0, };
int sum = 0;
int ans = 0;

void DFS(int cnt, int len) {
	if (cnt == len) {
		ans = max(ans, sum);
		return;
	}
	ROF(i, 9, 9 - len + 1) {
		if (visited[i]) continue;
		visited[i] = 1;
		sum += v[cnt] * i;
		DFS(cnt + 1, len);
		visited[i] = 0;
		sum -= v[cnt] * i;
	}
}

int main() {
	FASTIO;
	int N;
	string s;
	cin >> N;
	FOR(i, 1, N) {
		cin >> s;
		FOR(j, 0, s.size() - 1) {
			if (mp.count(s[j]))
				mp[s[j]] += pow(10, s.size() - 1 - j);
			else
				mp.insert({ s[j], pow(10, s.size() - 1 - j) });
		}
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		v.push_back((*it).second);
	}
	int len = v.size();
	DFS(0, len);
	cout << ans;

	return 0;
}