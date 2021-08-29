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
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int odd_cnt = 0;
		int even_cnt = 0;
		ll odd_sum = 0;
		ll even_sum = 0;
		vector<int> odd_v;
		FOR(i, 1, N) {
			cin >> arr[i];
			if (arr[i] % 2 == 1) {
				odd_cnt++;
				odd_v.push_back(i);
			}
			else if (arr[i] % 2 == 0) {
				even_cnt++;
			}
		}
		int odd_len = odd_v.size();
		if (abs(odd_cnt - even_cnt) >= 2) {
			cout << -1;
		}
		else {
			ll sum1 = 0, sum2 = 0;
			FOR(i, 0, odd_len - 1)
				sum1 += abs(odd_v[i] - (2 * i + 1));
			FOR(i, 0, odd_len - 1)
				sum2 += abs(odd_v[i] - (2 * i + 2));
			if (N % 2 == 1) {
				if (odd_cnt > even_cnt)
					cout << sum1;
				else if (odd_cnt < even_cnt)
					cout << sum2;
			}
			else if (N % 2 == 0)
				cout << min(sum1, sum2);
		}
		cout << "\n";
	}

	return 0;
}