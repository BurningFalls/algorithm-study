#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[101][101];
int bus[101];

int main() {
	FASTIO;
	int N, M;
	int sum = 0;
	cin >> N >> M;
	FOR(i, 1, M)
		cin >> bus[i];
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> arr[i][j];
		}
	}
	FOR(i, 1, M - 1) {
		sum += arr[bus[i]][bus[i + 1]];
	}
	cout << sum;


	return 0;
}