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
	int A, B, C;
	cin >> A >> B >> C;
	int N;
	cin >> N;
	int maxi = 0;
	FOR(i, 1, N) {
		int sum = 0;
		FOR(j, 1, 3) {
			int a, b, c;
			cin >> a >> b >> c;
			sum += A * a + B * b + C * c;
		}
		maxi = max(maxi, sum);
	}
	cout << maxi;


	return 0;
}