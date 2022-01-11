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
	int A, B, C, M;
	cin >> A >> B >> C >> M;
	int work = 0;
	int hard = 0;
	FOR(day, 1, 24) {
		if (hard + A > M) {
			hard = max(0, hard - C);
		}
		else if (hard + A <= M) {
			hard += A;
			work += B;
		}
	}
	cout << work;

	return 0;
}