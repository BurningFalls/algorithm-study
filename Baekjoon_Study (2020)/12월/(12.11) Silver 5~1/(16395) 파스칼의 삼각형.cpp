#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[31][31];

int main() {
	FASTIO;
	arr[1][1] = 1;
	FOR(i, 2, 30) {
		arr[i][1] = 1;
		FOR(j, 2, i - 1)
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		arr[i][i] = 1;
	}
	int n, k;
	cin >> n >> k;
	cout << arr[n][k];

	return 0;
}