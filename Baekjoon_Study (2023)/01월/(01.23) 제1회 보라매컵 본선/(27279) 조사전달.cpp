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
	cin >> N >> M;
	vector<ll> B(M + 1, 0);
	vector<ll> sum(M + 1, 0);
	FOR(i, 0, N - 1) {
		int num;
		cin >> num;
		sum[num]++;
	}
	FOR(i, 1, M) {
		cin >> B[i];
	}
	sort(ALL(B));

	ROF(i, M - 1, 1) {
		sum[i] = sum[i + 1] + sum[i];
		B[i] = B[i + 1] + B[i];
	}

	bool flag = true;
	ROF(i, M, 1) {
		if (sum[i] < B[i]) {
			flag = false;
			break;
		}
	}
	cout << (flag ? "YES" : "NO");

	return 0;
}