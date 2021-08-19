#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[200001];

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
			if (arr[i] == arr[1])
				cnt++;
		}
		if (cnt == n)
			cout << n;
		else
			cout << 1;
		cout << "\n";
	}

	return 0;
}