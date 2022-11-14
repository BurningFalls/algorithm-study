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

int main() {
	FASTIO;
	int N, M;
	cin >> N;
	map<string, string> mp[26][26];
	FOR(i, 0, N - 1) {
		string word;
		cin >> word;
		string tmp = word.substr(1, LEN(word) - 2);
		sort(ALL(tmp));
		tmp = word[0] + tmp + word[LEN(word) - 1];
		int front = word[0] - 'a';
		int back = word[LEN(word) - 1] - 'a';
		if (LEN(word) == 1) {
			mp[front][back][word] = word;
		}
		else {
			mp[front][back][tmp] = word;
		}
	}

	cin >> M;
	vector<string> ans;
	FOR(i, 1, M) {
		string word;
		cin >> word;
		string tmp = word.substr(1, LEN(word) - 2);
		sort(ALL(tmp));
		tmp = word[0] + tmp + word[LEN(word) - 1];
		int front = word[0] - 'a';
		int back = word[LEN(word) - 1] - 'a';
		if (LEN(word) == 1) {
			ans.push_back(mp[front][back][word]);
		}
		else {
			ans.push_back(mp[front][back][tmp]);
		}
	}

	FOR(i, 0, M - 1) {
		cout << ans[i] << " ";
	}

	return 0;
}