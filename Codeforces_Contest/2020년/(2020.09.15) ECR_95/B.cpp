#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int A[101];
int A2[101];
int L[101];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n;
		vector<int> v;
		cin >> n;
		FOR(i, 1, n) {
			cin >> A[i];
			A2[i] = A[i];
		}
		FOR(i, 1, n) {
			cin >> L[i];
			if (L[i] == 0)
				v.push_back(A[i]);
		}
		sort(v.begin(), v.end(), greater<int>());
		int idx = 0;
		FOR(i, 1, n) {
			if (L[i] == 0) {
				A2[i] = v[idx];
				idx++;
			}
		}
		FOR(i, 1, n) {
			cout << A2[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}