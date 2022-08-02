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
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int N = stoi(s);
		int num = 9;
		int sum = 0;
		vector<int> ans;
		while (num >= 1 && sum + num <= N) {
			ans.push_back(num);
			sum += num;
			num--;
		}
		if (N - sum != 0) {
			ans.push_back(N - sum);
		}
		ROF(i, LEN(ans) - 1, 0) {
			cout << ans[i];
		}
		cout << "\n";
	}

	return 0;
}