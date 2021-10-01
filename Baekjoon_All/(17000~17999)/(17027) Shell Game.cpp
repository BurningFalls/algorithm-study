#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int arr[101][3];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 0, 2) {
			cin >> arr[i][j];
		}
	}
	int maxi = 0;
	FOR(i, 1, 3) {
		int idx = i;
		int cnt = 0;
		FOR(j, 1, N) {
			if (idx == arr[j][0])
				idx = arr[j][1];
			else if (idx == arr[j][1])
				idx = arr[j][0];
			if (arr[j][2] == idx)
				cnt++;
		}
		maxi = max(maxi, cnt);
	}
	cout << maxi;

	return 0;
}