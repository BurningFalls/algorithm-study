#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int main() {
	FASTIO;
	int wanted;
	int M, N;
	cin >> wanted;
	cin >> M >> N;
	vector<int> pieceA(2 * M);
	vector<int> pieceB(2 * N);
	vector<int> sumA, sumB;
	int tmp1 = 0, tmp2 = 0;
	FOR(i, 0, M - 1) {
		cin >> pieceA[i];
		tmp1 += pieceA[i];
		if (i != M - 1) {
			pieceA[i + M] = pieceA[i];
		}
	}
	FOR(i, 0, N - 1) {
		cin >> pieceB[i];
		tmp2 += pieceB[i];
		if (i != N - 1) {
			pieceB[i + N] = pieceB[i];
		}
	}
	sumA.push_back(0);
	sumB.push_back(0);
	if (tmp1 <= wanted)
		sumA.push_back(tmp1);
	if (tmp2 <= wanted)
		sumB.push_back(tmp2);
	FOR(i, 0, M - 1) {
		int sum = 0;
		FOR(j, 0, M - 2) {
			sum += pieceA[i + j];
			if (sum > wanted)
				break;
			sumA.push_back(sum);
		}
	}
	FOR(i, 0, N - 1) {
		int sum = 0;
		FOR(j, 0, N - 2) {
			sum += pieceB[i + j];
			if (sum > wanted)
				break;
			sumB.push_back(sum);
		}
	}
	sort(ALL(sumB));
	ll ans = 0;
	for(int x : sumA) {
		int lb = lower_bound(ALL(sumB), wanted - x) - sumB.begin();
		int ub = upper_bound(ALL(sumB), wanted - x) - sumB.begin();
		ans += (ll)ub - lb;
	}
	cout << ans;

	return 0;
}