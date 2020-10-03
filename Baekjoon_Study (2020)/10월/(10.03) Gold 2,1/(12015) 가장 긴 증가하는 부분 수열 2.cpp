#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1000001];
int ans[1000001] = { 0, };

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	ans[1] = arr[1];
	int idx = 1;
	FOR(i, 2, N) {
		int lb = lower_bound(ans + 1, ans + idx + 1, arr[i]) - ans;
		if (ans[lb] == 0)
			idx++;
		ans[lb] = arr[i];
	}
	cout << idx;

	return 0;
}