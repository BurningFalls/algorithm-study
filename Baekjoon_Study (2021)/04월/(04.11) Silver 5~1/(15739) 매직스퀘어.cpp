#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int arr[101][101];
int SUM;
bool exist[10001] = { 0, };

bool Check() {
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			exist[arr[i][j]] = 1;
		}
	}
	FOR(i, 1, N * N) {
		if (!exist[i])
			return false;
	}
	int sum = 0;
	FOR(i, 1, N) {
		sum = 0;
		FOR(j, 1, N) {
			sum += arr[i][j];
		}
		if (sum != SUM)
			return false;
	}
	FOR(i, 1, N) {
		sum = 0;
		FOR(j, 1, N) {
			sum += arr[j][i];
		}
		if (sum != SUM)
			return false;
	}
	sum = 0;
	FOR(i, 1, N) {
		sum += arr[i][i];
	}
	if (sum != SUM)
		return false;
	sum = 0;
	FOR(i, 1, N) {
		sum += arr[i][N - i + 1];
	}
	if (sum != SUM)
		return false;
	return true;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> arr[i][j];
		}
	}
	SUM = N * (N * N + 1) / 2;
	cout << ((Check()) ? "TRUE" : "FALSE");

	return 0;
}