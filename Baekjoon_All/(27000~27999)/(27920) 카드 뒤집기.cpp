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
	cout << "YES\n";

	vector<int> pos(N + 1, 0);
	int idx = 1;
	for (int i = (N % 2 == 0 ? N - 1 : N); i >= 1; i -= 2) {
		cout << i << " ";
		pos[i] = idx;
		idx++;
	}
	for (int i = 2; i <= N; i += 2) {
		cout << i << " ";
		pos[i] = idx;
		idx++;
	}
	cout << "\n";

	FOR(i, 1, N) {
		cout << pos[i] << " ";
	}

	return 0;
}