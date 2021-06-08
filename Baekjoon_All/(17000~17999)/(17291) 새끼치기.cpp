#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[21][5] = { 0, };

int main() {
	FASTIO;
	int N;
	cin >> N;
	arr[1][0] = 1;
	arr[1][3] = 1;
	FOR(i, 2, N) {
		if (i % 2 == 1) {
			arr[i][3] += arr[i - 1][0];
		}
		else if (i % 2 == 0) {
			arr[i][4] += arr[i - 1][0];
		}
		FOR(j, 2, 4) {
			arr[i][j - 1] += arr[i - 1][j];
		}
		ll sum = 0;
		FOR(j, 1, 4)
			sum += arr[i][j];
		arr[i][0] = sum;
	}
	cout << arr[N][0];


	return 0;
}