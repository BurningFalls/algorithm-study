#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[50001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int n;
		int cnt = 0;
		cin >> n;
		FOR(i, 1, n) {
			cin >> arr[i];
		}
		FOR(i, 1, n - 1) {
			if (arr[i] > arr[i + 1])
				cnt++;
		}
		if (cnt == n - 1)
			cout << "NO";
		else
			cout << "YES";
		cout << "\n";
	}

	return 0;
}