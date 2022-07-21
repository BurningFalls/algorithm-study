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
	vector<int> A(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	vector<map<int, int>> v(N);
	v[0][0] = 1;
	v[0][A[0]] = 0;
	FOR(i, 1, N - 1) {
		for (auto x : v[i - 1]) {
			if (x.first == 0) {
				v[i][A[i]] = (v[i].count(A[i]) ? min(v[i][A[i]], x.second) : x.second);
				v[i][0] = (v[i].count(0) ? min(v[i][0], x.second + 1) : x.second + 1);
			}
			else if (x.first <= A[i]) {
				int diff = A[i] - x.first;
				v[i][diff] = (v[i].count(diff) ? min(v[i][diff], x.second + 1) : x.second + 1);
			}
		}
	}
	int mini = INF;
	for (auto x : v[N - 1]) {
		mini = min(mini, (x.first == 0 ? x.second : x.second + 1));
	}
	cout << mini;

	return 0;
}