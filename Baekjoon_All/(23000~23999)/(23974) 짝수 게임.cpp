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
	int N, K;
	cin >> N >> K;
	if (N == 0) {
		cout << (K % 6 == 1 ? "HS" : "YG");
	}
	else if (N == 1) {
		cout << (K % 6 == 0 || K % 6 == 5 ? "HS" : "YG");
	}


	return 0;
}