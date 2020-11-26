#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[101];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	int ans = 0;
	ROF(i, N, 2) {
		if (arr[i - 1] >= arr[i]) {
			ans += (arr[i - 1] - (arr[i] - 1));
			arr[i - 1] = arr[i] - 1;
		}
	}
	cout << ans;

	return 0;
}