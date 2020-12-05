#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int K;
	cin >> K;
	int arr[6][2];
	int cnt[5] = { 0, };
	FOR(i, 0, 5) {
		FOR(j, 0, 1) {
			cin >> arr[i][j];
			if (j == 0)
				cnt[arr[i][0]]++;
		}
	}
	int small, big;
	if (cnt[1] == 2 && cnt[3] == 2) {
		FOR(i, 0, 5) {
			if (arr[i][0] == 1 && arr[(i + 1) % 6][0] == 3) {
				small = arr[i][1] * arr[(i + 1) % 6][1];
			}
			else if (arr[i][0] == 4 && arr[(i + 1) % 6][0] == 2) {
				big = arr[i][1] * arr[(i + 1) % 6][1];
			}
		}
	}
	else if (cnt[1] == 2 && cnt[4] == 2) {
		FOR(i, 0, 5) {
			if (arr[i][0] == 4 && arr[(i + 1) % 6][0] == 1) {
				small = arr[i][1] * arr[(i + 1) % 6][1];
			}
			else if (arr[i][0] == 2 && arr[(i + 1) % 6][0] == 3) {
				big = arr[i][1] * arr[(i + 1) % 6][1];
			}
		}
	}
	else if (cnt[2] == 2 && cnt[4] == 2) {
		FOR(i, 0, 5) {
			if (arr[i][0] == 2 && arr[(i + 1) % 6][0] == 4) {
				small = arr[i][1] * arr[(i + 1) % 6][1];
			}
			else if (arr[i][0] == 3 && arr[(i + 1) % 6][0] == 1) {
				big = arr[i][1] * arr[(i + 1) % 6][1];
			}
		}
	}
	else if (cnt[2] == 2 && cnt[3] == 2) {
		FOR(i, 0, 5) {
			if (arr[i][0] == 3 && arr[(i + 1) % 6][0] == 2) {
				small = arr[i][1] * arr[(i + 1) % 6][1];
			}
			else if (arr[i][0] == 1 && arr[(i + 1) % 6][0] == 4) {
				big = arr[i][1] * arr[(i + 1) % 6][1];
			}
		}
	}
	cout << K * (big - small);

	return 0;
}