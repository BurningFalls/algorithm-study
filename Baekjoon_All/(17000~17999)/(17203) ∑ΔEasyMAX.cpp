#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int A[1001];
int diff[1001];

int main() {
	FASTIO;
	int N, Q;
	cin >> N >> Q;
	A[0] = 0;
	FOR(i, 1, N) {
		cin >> A[i];
		diff[i] = abs(A[i] - A[i - 1]);
	}
	FOR(i, 1, Q) {
		int start, end;
		cin >> start >> end;
		if (end - 1 < start)
			cout << 0;
		else {
			int sum = 0;
			FOR(j, start + 1, end) {
				sum += diff[j];
			}
			cout << sum;
		}
		cout << "\n";
	}


	return 0;
}