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
	string S;
	set<int> v = { 'A', 'E', 'I', 'O', 'U' };
	cin >> N >> M;
	cin >> S;

	int idx1 = N - 1;
	while (idx1 >= 0 && v.count(S[idx1])) {
		idx1--;
	}
	int idx2 = idx1 - 1;
	while (idx2 >= 0 && S[idx2] != 'A') {
		idx2--;
	}
	int idx3 = idx2 - 1;
	while (idx3 >= 0 && S[idx3] != 'A') {
		idx3--;
	}

	if (idx1 < 0 || idx2 < 0 || idx3 < 0 || idx3 + 3 < M) {
		cout << "NO";
	}
	else {
		cout << "YES\n";
		FOR(i, 0, M - 4) {
			cout << S[i];
		}
		cout << "AA";
		cout << S[idx1];
	}

	return 0;
}