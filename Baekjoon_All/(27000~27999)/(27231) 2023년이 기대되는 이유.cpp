#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		ll N;
		cin >> N;
		string s = to_string(N);
		int len = LEN(s);

		bool flag = true;
		FOR(i, 0, len - 1) {
			if (s[i] != '0' && s[i] != '1') {
				flag = false;
			}
		}
		if (flag) {
			cout << "Hello, BOJ 2023!\n";
			continue;
		}

		set<int> sums;
		FOR(bm, 0, (1 << (len - 1)) - 1) {
			vector<string> v;
			string tmp = "";
			tmp = s[0];
			FOR(i, 0, len - 2) {
				if (bm & (1 << i)) {
					v.push_back(tmp);
					tmp = s[i + 1];
				}
				else {
					tmp += s[i + 1];
				}
			}
			v.push_back(tmp);
			
			int sum = 0;
			FOR(i, 0, LEN(v) - 1) {
				sum += stoi(v[i]);
			}
			sums.insert(sum);
		}

		vector<ll> nums;
		int tn = N;
		while (tn) {
			nums.push_back(tn % 10);
			tn /= 10;
		}
		vector<ll> ch(nums);
		int m = 1;
		int ans = 0;
		while (true) {
			ll sum = 0;
			FOR(i, 0, LEN(ch) - 1) {
				sum += ch[i];
				ch[i] *= nums[i];
			}
			if (sums.count(sum)) {
				ans++;
			}
			if (sum > N) break;
			m++;
		}
		cout << ans << "\n";
	}

	return 0;
}