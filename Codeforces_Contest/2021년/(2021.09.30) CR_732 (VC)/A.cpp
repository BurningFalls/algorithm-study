#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int A[101];
int B[101];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		vector<int> inc, dec;
		cin >> N;
		FOR(i, 1, N)
			cin >> A[i];
		FOR(i, 1, N)
			cin >> B[i];
		FOR(i, 1, N) {
			if (A[i] > B[i]) {
				FOR(j, 1, A[i] - B[i])
					dec.push_back(i);
			}
			else if (A[i] < B[i]) {
				FOR(j, 1, B[i] - A[i])
					inc.push_back(i);
			}
		}
		if (LEN(inc) != LEN(dec)) {
			cout << -1 << "\n";
			continue;
		}
		cout << LEN(inc) << "\n";
		FOR(i, 0, LEN(inc) - 1)
			cout << dec[i] << " " << inc[i] << "\n";
	}

	return 0;
}