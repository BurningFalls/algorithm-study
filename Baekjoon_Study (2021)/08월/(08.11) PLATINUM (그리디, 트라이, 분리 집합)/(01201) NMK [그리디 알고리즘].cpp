#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[501];

int main() {
	FASTIO;
	int N, M, K;
	cin >> N >> M >> K;
	if (M + K - 1 <= N && N <= M * K) {
		FOR(i, 0, N - 1)
			arr[i] = i + 1;
		int idx = 0;
		FOR(i, 1, M) {
			// idx + K -> reverse 했을 때 K개가 감소하므로
			// N - M + i -> i번째 그룹의 최소 index는 N - M + i
			int tmp = min(idx + K, N - M + i);
			reverse(arr + idx, arr + tmp);
			idx = tmp;
		}
		FOR(i, 0, N - 1)
			cout << arr[i] << " ";
	}
	else
		cout << -1;


	return 0;
}