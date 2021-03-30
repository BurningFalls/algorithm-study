#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int M, N;
int L[1000001];

int main() {
	FASTIO;
	cin >> M >> N;
	FOR(i, 1, N)
		cin >> L[i];
	sort(L + 1, L + N + 1);
	int ans = 0;
	int left = 1, right = L[N];
	while (left <= right) {
		int mid = (left + right) / 2;
		int result = 0;
		FOR(i, 1, N)
			result += (L[i] / mid);
		if (result < M) {
			right = mid - 1;
		}
		else if (result >= M) {
			left = mid + 1;
			ans = max(ans, mid);
		}
	}
	cout << ans;


	return 0;
}