#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int main() {
	FASTIO;
	int N;
	int mini = INF;
	int arr[2002];
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	FOR(i, N + 1, 2 * N)
		arr[i] = arr[i - N];
	FOR(start, 1, N) {
		int sum = 0;
		FOR(i, start + 1, start + N - 1)
			sum += (i - start) * arr[i];
		mini = min(mini, sum);
	}
	cout << mini;

	return 0;
}