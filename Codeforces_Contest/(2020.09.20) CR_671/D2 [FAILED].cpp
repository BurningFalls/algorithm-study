#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[100001];
int ans[100001];
int ans2[100001];
int visited[100001] = { 0, };

int main() {
	FASTIO;
	int n;
	cin >> n;
	FOR(i, 1, n) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1, greater<int>());
	int max_cnt = 0;
	int node = 0;
	int cnt = 1;
	FOR(i, 1, n - 1) {
		if (arr[i] == arr[i + 1])
			cnt++;
		else {
			if (max_cnt < cnt) {
				max_cnt = cnt;
				node = arr[i];
			}
			cnt = 1;
		}
	}
	FOR(i, 1, max_cnt)
		ans[i] = node;
	visited[node] = 1;
	int Idx = max_cnt + 1;
	FOR(i, 1, n) {
		if (arr[i] == node) continue;
		ans[Idx] = arr[i];
		Idx++;
	}
	if (n % 2 == 0) {
		int idx = 1;
		for (int i = 1; i <= n; i += 2) {
			ans2[i] = ans[idx];
			idx++;
		}
		for (int i = n; i >= 1; i -= 2) {
			ans2[i] = ans[idx];
			idx++;
		}
	}
	else if (n % 2 == 1) {
		int idx = 1;
		for (int i = 1; i <= n; i += 2) {
			ans2[i] = ans[idx];
			idx++;
		}
		for (int i = 2; i <= n; i += 2) {
			ans2[i] = ans[idx];
			idx++;
		}
	}
	int Cnt = 0;
	FOR(i, 2, n - 1) {
		if (ans2[i - 1] > ans2[i] && ans2[i] < ans2[i + 1])
			Cnt++;
	}
	cout << Cnt << "\n";
	FOR(i, 1, n)
		cout << ans2[i] << " ";

	return 0;
}