#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int arr[3001];

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int sum = 0;
		int maxi = 0;
		FOR(i, 1, N) {
			cin >> arr[i];
			sum += arr[i];
			maxi = max(maxi, arr[i]);
		}
		int sq = sqrt(sum);
		vector<int> v;
		FOR(i, 1, sq) {
			if (sum % i == 0) {
				if (i == sum / i) {
					if (i >= maxi)
						v.push_back(i);
				}
				else {
					if (i >= maxi)
						v.push_back(i);
					if (sum / i >= maxi)
						v.push_back(sum / i);
				}
			}
		}
		sort(v.begin(), v.end());
		int ans = -1;
		for (int x : v) {
			bool flag = true;
			int num = 0;
			FOR(i, 1, N) {
				num += arr[i];
				if (num > x) {
					flag = false;
					break;
				}
				else if (num == x) {
					num = 0;
				}
			}
			if (flag) {
				int cnt = sum / x;
				ans = N - cnt;
				break;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}