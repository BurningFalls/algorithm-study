#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N, M;
	int arr[31][31];
	cin >> N >> M;
	FOR(i, 1, N) {
		FOR(j, 1, M) {
			cin >> arr[i][j];
		}
	}
	int max_sum = 0;
	FOR(i, 1, M) {
		FOR(j, i + 1, M) {
			FOR(k, j + 1, M) {
				int sum = 0;
				FOR(t, 1, N) {
					int maxi = max({ arr[t][i], arr[t][j], arr[t][k] });
					sum += maxi;
				}
				max_sum = max(max_sum, sum);
			}
		}
	}
	cout << max_sum;


	return 0;
}