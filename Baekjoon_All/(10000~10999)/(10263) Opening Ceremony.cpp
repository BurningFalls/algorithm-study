#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int arr[100001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	int idx = 1;
	int mini = INF;
	while (idx <= N) {
		int ub = upper_bound(arr + idx, arr + N + 1, arr[idx]) - arr;
		idx = ub - 1;
		mini = min(mini, (N - idx) + arr[idx]);
		idx++;
	}
	cout << min(mini, N);

	return 0;
}