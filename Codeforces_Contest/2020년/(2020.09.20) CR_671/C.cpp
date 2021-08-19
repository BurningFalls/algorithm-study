#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[1001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n, x;
		int sum = 0;
		int cnt = 0;
		cin >> n >> x;
		FOR(i, 1, n) {
			cin >> arr[i];
			if (arr[i] == x)
				cnt++;
			sum += (x - arr[i]);
		}
		if (cnt == n)
			cout << 0;
		else if (cnt >= 1) {
			cout << 1;
		}
		else if (cnt == 0) {
			if (sum == 0)
				cout << 1;
			else
				cout << 2;
		}
		cout << "\n";
	}

	return 0;
}