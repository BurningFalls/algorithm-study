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
	int N, D, K, C;
	cin >> N >> D >> K >> C;
	vector<int> plate(2 * N - 1);
	FOR(i, 0, N - 1) {
		cin >> plate[i];
		if (i != N - 1) {
			plate[i + N] = plate[i];
		}
	}
	int start = 0, end = start + K - 1;
	vector<int> fish(D + 1, 0);
	int cnt = 1;
	FOR(i, start, end) {
		if (fish[plate[i]]++ == 0) {
			if (!(plate[i] == C)) {
				cnt++;
			}
		}
	}
	int maxi = cnt;
	while (start < N - 1) {
		if (--fish[plate[start]] == 0) {
			if (!(plate[start] == C)) {
				cnt--;
			}
		}
		start++;
		end++;
		if (fish[plate[end]]++ == 0) {
			if (!(plate[end] == C)) {
				cnt++;
			}
		}
		maxi = max(maxi, cnt);
	}
	cout << maxi;


	return 0;
}