#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[30001];
int visited[3001] = { 0, };

int main() {
	FASTIO;
	int N, D, K, C;
	cin >> N >> D >> K >> C;
	int start = 0;
	int end = K - 1;
	int cnt = 1;
	int ans = 0;
	visited[C] = 1;
	FOR(i, 0, N - 1) {
		cin >> arr[i];
		if (i <= K - 1) {
			if (visited[arr[i]] == 0)
				cnt++;
			visited[arr[i]]++;
		}
	}
	ans = max(ans, cnt);
	while (start < N - 1) {
		visited[arr[start]]--;
		if (visited[arr[start]] == 0)
			cnt--;
		start = start + 1;
		end = (end + 1) % N;
		if (visited[arr[end]] == 0)
			cnt++;
		visited[arr[end]]++;
		
		ans = max(ans, cnt);
	}
	cout << ans;

	return 0;
}