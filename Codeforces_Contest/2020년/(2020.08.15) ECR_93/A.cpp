#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[50001];
int n;

int main() {
	FASTIO;
	int T;
	cin >> T;
	FOR(t, 0, T - 1) {
		cin >> n;
		FOR(i, 0, n - 1) {
			cin >> arr[i];
		}
		if (arr[0] + arr[1] <= arr[n - 1])
			cout << 1 << " " << 2 << " " << n;
		else
			cout << -1;
		cout << "\n";
	}

	return 0;
}