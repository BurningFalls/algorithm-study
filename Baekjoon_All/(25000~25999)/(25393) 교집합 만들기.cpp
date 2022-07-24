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
#define MAX 1000001

vector<int> Left(MAX, INF), Right(MAX, -1);
vector<set<int>> nums(MAX, set<int>());

int main() {
	FASTIO;
	int N, Q;
	cin >> N;
	FOR(i, 1, N) {
		int l, r;
		cin >> l >> r;
		Right[l] = max(Right[l], r);
		Left[r] = min(Left[r], l);
		nums[l].insert(r);
	}
	cin >> Q;
	FOR(q, 1, Q) {
		int l, r;
		cin >> l >> r;
		if (nums[l].count(r)) {
			cout << 1;
		}
		else if (Right[l] >= r && Left[r] <= l) {
			cout << 2;
		}
		else {
			cout << -1;
		}
		cout << "\n";
	}

	return 0;
}