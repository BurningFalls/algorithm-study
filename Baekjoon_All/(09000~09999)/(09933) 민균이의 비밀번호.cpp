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
	int N;
	cin >> N;
	vector<string > s1(N), s2(N);
	FOR(i, 0, N - 1) {
		string tmp;
		cin >> tmp;
		s1[i] = tmp;
		reverse(ALL(tmp));
		s2[i] = tmp;
	}

	FOR(i, 0, N - 1) {
		FOR(j, i, N - 1) {
			if (s1[i] == s2[j]) {
				cout << LEN(s1[i]) << " " << s1[i][LEN(s1[i]) / 2];
			}
		}
	}

	return 0;
}