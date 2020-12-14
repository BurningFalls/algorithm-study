#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
char arr[51][51];

int Eat() {
	int maximum = 0;
	FOR(i, 1, N) {
		int cnt = 1;
		int max_cnt = 0;
		FOR(j, 2, N) {
			if (arr[i][j] == arr[i][j - 1])
				cnt++;
			else {
				max_cnt = max(max_cnt, cnt);
				cnt = 1;
			}
		}
		max_cnt = max(max_cnt, cnt);
		maximum = max(maximum, max_cnt);
	}
	FOR(i, 1, N) {
		int cnt = 1;
		int max_cnt = 0;
		FOR(j, 2, N) {
			if (arr[j][i] == arr[j - 1][i])
				cnt++;
			else {
				max_cnt = max(max_cnt, cnt);
				cnt = 1;
			}
		}
		max_cnt = max(max_cnt, cnt);
		maximum = max(maximum, max_cnt);
	}
	return maximum;
}

int main() {
	FASTIO;
	int ans = 0;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> arr[i][j];
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, N - 1) {
			if (arr[i][j] == arr[i][j + 1]) continue;
			swap(arr[i][j], arr[i][j + 1]);
			ans = max(ans, Eat());
			swap(arr[i][j], arr[i][j + 1]);
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, N - 1) {
			if (arr[j][i] == arr[j + 1][i]) continue;
			swap(arr[j][i], arr[j + 1][i]);
			ans = max(ans, Eat());
			swap(arr[j][i], arr[j + 1][i]);
		}
	}
	cout << ans;

	return 0;
}