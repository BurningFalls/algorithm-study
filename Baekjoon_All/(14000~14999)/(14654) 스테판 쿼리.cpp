#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

/*
1 < 2
2 < 3
3 < 1
*/

int arr1[301];
int arr2[301];
bool win[3][302] = { 0, };

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr1[i];
	FOR(i, 1, N)
		cin >> arr2[i];
	FOR(i, 1, N) {
		if ((arr1[i] == 1 && arr2[i] == 2) ||
			(arr1[i] == 2 && arr2[i] == 3) ||
			(arr1[i] == 3 && arr2[i] == 1)) {
			win[2][i] = 1;
		}
		else if ((arr1[i] == 2 && arr2[i] == 1) ||
			(arr1[i] == 3 && arr2[i] == 2) ||
			(arr1[i] == 1 && arr2[i] == 3)) {
			win[1][i] = 1;
		}
		else if ((arr1[i] == 1 && arr2[i] == 1) ||
			(arr1[i] == 2 && arr2[i] == 2) ||
			(arr1[i] == 3 && arr2[i] == 3)) {
			if (win[1][i - 1] == 1)
				win[2][i] = 1;
			else if (win[2][i - 1] == 1)
				win[1][i] = 1;
		}
	}
	int maxi = 0;
	int cnt = 0;
	FOR(i, 1, N + 1) {
		if (win[1][i])
			cnt++;
		else {
			maxi = max(maxi, cnt);
			cnt = 0;
		}
	}
	FOR(i, 1, N + 1) {
		if (win[2][i])
			cnt++;
		else {
			maxi = max(maxi, cnt);
			cnt = 0;
		}
	}
	cout << maxi;

	return 0;
}