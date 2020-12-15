#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int ans[100];
int arr[100];

int main() {
	FASTIO;
	int N;
	int maximum = 0;
	cin >> N;
	FOR(i, 0, N) {
		vector<int> v;
		int num = N;
		int idx = 1;
		arr[1] = num;
		arr[2] = i;
		while (arr[idx] - arr[idx + 1] >= 0) {
			arr[idx + 2] = arr[idx] - arr[idx + 1];
			idx++;
		}
		int len = idx + 1;
		if (len > maximum) {
			maximum = len;
			FOR(j, 1, len)
				ans[j] = arr[j];
		}
	}
	cout << maximum << "\n";
	FOR(i, 1, maximum)
		cout << ans[i] << " ";

	return 0;
}