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
	cin >> N;
	vector<int> v(N);
	vector<int> Ldp(N), Rdp(N);
	vector<int> max_Ldp(N), max_Rdp(N);
	FOR(i, 0, N - 1) {
		cin >> v[i];
	}

	Ldp[0] = v[0];
	max_Ldp[0] = Ldp[0];
	FOR(i, 1, N - 1) {
		Ldp[i] = max(Ldp[i - 1] + v[i], v[i]);
		max_Ldp[i] = max(max_Ldp[i - 1], Ldp[i]);
	}
	Rdp[N - 1] = v[N - 1];
	max_Rdp[N - 1] = Rdp[N - 1];
	ROF(i, N - 2, 0) {
		Rdp[i] = max(Rdp[i + 1] + v[i], v[i]);
		max_Rdp[i] = max(max_Rdp[i + 1], Rdp[i]);
	}

	int maxi = -INF;
	FOR(k, 1, N - 2) {
		maxi = max(maxi, max_Ldp[k - 1] + max_Rdp[k + 1]);
	}
	cout << maxi;

	return 0;
}