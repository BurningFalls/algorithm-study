#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001];

int main() {
	FASTIO;
	int N, Q;
	cin >> N >> Q;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	FOR(i, 1, Q) {
		int A, B;
		cin >> A >> B;
		int lb = lower_bound(arr + 1, arr + N + 1, A) - arr;
		int ub = upper_bound(arr + 1, arr + N + 1, B) - arr;
		cout << ub - lb << "\n";
	}

	return 0;
}