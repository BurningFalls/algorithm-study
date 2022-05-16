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

int main() {
	FASTIO;
	int N;
	string S;
	cin >> N;
	cin >> S;
	vector<int> v(N);
	v[0] = 1;
	int maxi = 1;
	FOR(i, 1, N - 1) {
		if (S[i] == S[i - 1] + 1 || S[i] == S[i - 1] - 1) {
			v[i] = v[i - 1] + 1;
		}
		else {
			v[i] = 1;
		}
		maxi = max(maxi, v[i]);
	}
	cout << (maxi >= 5 ? "YES" : "NO");

	return 0;
}