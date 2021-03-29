#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int arr[1000001];
int cnt[1000001];

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	int ans = 0;
	FOR(i, 1, N) {
		if (cnt[arr[i]] == 0) {
			ans++;
			cnt[arr[i] - 1] += 1;
		}
		else {
			cnt[arr[i]] -= 1;
			cnt[arr[i] - 1] += 1;
		}
	}
	cout << ans;


	return 0;
}