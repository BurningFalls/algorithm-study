#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int arr1[100001];
int mini[100001];
int arr2[100001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		FOR(i, 1, N) {
			cin >> arr1[i];
			mini[(arr1[i] + 1) / 2] = i - 1;
		}
		FOR(i, 1, N)
			cin >> arr2[i];
		FOR(i, 2, N) {
			mini[i] = min(mini[i - 1], mini[i]);
		}
		int MIN = 300000;
		FOR(i, 1, N) {
			MIN = min(MIN, (i - 1) + mini[arr2[i] / 2]);
		}
		cout << MIN << "\n";
	}

	return 0;
}