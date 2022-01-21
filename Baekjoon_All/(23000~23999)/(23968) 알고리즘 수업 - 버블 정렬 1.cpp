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
	vector<int> A(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	int cnt = 0;
	int a = 0, b = 0;
	ROF(i, N - 1, 1) {
		FOR(j, 0, i - 1) {
			if (A[j] > A[j + 1]) {
				swap(A[j], A[j + 1]);
				cnt++;
				if (cnt == K) {
					a = min(A[j], A[j + 1]);
					b = max(A[j], A[j + 1]);
					i = 0;
					break;
				}
			}
		}
	}

	if (a == 0 && b == 0) {
		cout << -1;
	}
	else {
		cout << a << " " << b;
	}

	return 0;
}