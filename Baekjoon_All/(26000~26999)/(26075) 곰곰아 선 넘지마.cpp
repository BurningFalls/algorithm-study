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
	string S, T;
	cin >> N >> M;
	cin >> S >> T;
	vector<ll> idx1, idx2;
	FOR(i, 0, LEN(S) - 1) {
		if (S[i] == '1') {
			idx1.push_back(i);
		}
	}
	FOR(i, 0, LEN(T) - 1) {
		if (T[i] == '1') {
			idx2.push_back(i);
		}
	}
	ll diff = 0;
	FOR(i, 0, M - 1) {
		diff += abs(idx1[i] - idx2[i]);
	}
	if (diff % 2 == 0) {
		cout << diff * diff / 2;
	}
	else if (diff % 2 == 1) {
		cout << (diff * diff + 1) / 2;
	}

	return 0;
}