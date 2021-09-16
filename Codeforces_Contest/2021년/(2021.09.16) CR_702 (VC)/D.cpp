#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int arr[101];
int depth[101];

void DFS(int left, int right, int d) {
	if (left > right)
		return;
	int maxi = 0;
	int max_idx = 0;
	FOR(i, left, right) {
		if (maxi < arr[i]) {
			maxi = arr[i];
			max_idx = i;
		}
	}
	depth[max_idx] = d;
	DFS(left, max_idx - 1, d + 1);
	DFS(max_idx + 1, right, d + 1);
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		MEMSET(depth, 0);
		int N;
		cin >> N;
		int maxi = 0;
		int max_idx = 0;
		FOR(i, 1, N)
			cin >> arr[i];
		DFS(1, N, 0);
		FOR(i, 1, N)
			cout << depth[i] << " ";
		cout << "\n";
	}

	return 0;
}