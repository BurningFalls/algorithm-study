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

int cnt[26] = { 3,2,1,2,3,3,2,3,3,2,2,1,2,2,1,2,2,2,1,2,1,1,1,2,2,1 };

int main() {
	FASTIO;
	string A, B;
	cin >> A >> B;
	vector<int> v;
	FOR(i, 0, LEN(A) - 1) {
		v.push_back(cnt[A[i] - 'A']);
		v.push_back(cnt[B[i] - 'A']);
	}
	vector<int> v2;
	while (LEN(v) > 2) {
		FOR(i, 0, LEN(v) - 2) {
			v2.push_back((v[i] + v[i + 1]) % 10);
		}
		v.clear();
		v = v2;
		v2.clear();
	}
	cout << v[0] << v[1];


	return 0;
}