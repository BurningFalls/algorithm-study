#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001];

int main() {
	FASTIO;
	int N, X;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	cin >> X;
	sort(arr + 1, arr + N + 1);
	int ans = 0;
	FOR(i, 1, N) {
		int num = X - arr[i];
		if (arr[i] == num) continue;
		bool flag = binary_search(arr + 1, arr + N + 1, num);
		if (flag)
			ans++;
	}
	cout << ans / 2;

	return 0;
}