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
	sort(ALL(A));
	vector<int> v;
	FOR(i, 0, min(N - 1, 10)) {
		FOR(j, 0, min(N - 1, 10)) {
			if (i == j) continue;
			string s = to_string(A[i]);
			s += to_string(A[j]);
			v.push_back(stoi(s));
		}
	}
	sort(ALL(v));
	cout << v[2];

	return 0;
}