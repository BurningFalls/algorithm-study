#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[101];

int main() {
	FASTIO;
	memset(arr, -1, sizeof(arr));
	int N;
	int cnt = 0;
	cin >> N;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		if (arr[a] == -1)
			arr[a] = b;
		else if (arr[a] == 0) {
			if (b == 1) {
				cnt++;
				arr[a] = 1;
			}
		}
		else if (arr[a] == 1) {
			if (b == 0) {
				cnt++;
				arr[a] = 0;
			}
		}
	}
	cout << cnt;

	return 0;
}