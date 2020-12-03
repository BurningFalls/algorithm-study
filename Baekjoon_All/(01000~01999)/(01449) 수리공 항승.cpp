#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1001];

int main() {
	FASTIO;
	int N, L;
	cin >> N >> L;
	FOR(i, 1, N)
		cin >> arr[i];
	int idx = 1;
	sort(arr + 1, arr + N + 1);
	int cnt = 0;
	while (idx <= N) {
		int start = arr[idx];
		int end = arr[idx] + (L - 1);
		while (arr[idx] <= end)
			idx++;
		cnt++;
	}
	cout << cnt;

	return 0;
}