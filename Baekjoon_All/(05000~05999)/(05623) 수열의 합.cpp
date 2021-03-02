#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N;
int arr[1001][1001];

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) FOR(j, 1, N)
		cin >> arr[i][j];
	if (N == 2) {
		cout << "1 1";
		return 0;
	}
	int x = (arr[1][2] + arr[1][3] - arr[2][3]) / 2;
	cout << x << " ";
	FOR(i, 1, N - 1) {
		x = arr[i][i + 1] - x;
		cout << x << " ";
	}

	return 0;
}