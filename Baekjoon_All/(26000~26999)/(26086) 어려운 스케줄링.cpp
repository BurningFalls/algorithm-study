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
	int N, Q, K;
	cin >> N >> Q >> K;
	deque<pii> dq;
	bool flag = true;
	vector<int> nums;
	FOR(i, 1, Q) {
		int idx;
		cin >> idx;
		if (idx == 0) {
			int p;
			cin >> p;
			nums.push_back(p);
			int len = LEN(nums);
			if (flag) {
				dq.push_back({ len, len });
			}
			else if (!flag) {
				dq.push_front({ len, len });
			}
		}
		else if (idx == 1) {
			dq.clear();
			flag = true;
			dq.push_back({ LEN(nums), 1});
		}
		else if (idx == 2) {
			flag = !flag;
		}
	}

	int ans = 0;
	if (flag) {
		int cnt = 0;
		while (cnt < K) {
			int a = dq.back().first;
			int b = dq.back().second;
			if (a == b) {
				ans = nums[a - 1];
				dq.pop_back();
				cnt++;
			}
			else if (a != b) {
				if (cnt + a < K) {
					dq.pop_back();
					cnt += a;
				}
				else if (cnt + a >= K) {
					sort(nums.begin(), nums.begin() + a);
					ans = nums[K - cnt - 1];
					break;
				}
			}
		}
	}
	else if (!flag) {
		int cnt = 0;
		while (cnt < K) {
			int a = dq.front().first;
			int b = dq.front().second;
			if (a == b) {
				ans = nums[a - 1];
				dq.pop_front();
				cnt++;
			}
			else if (a != b) {
				if (cnt + a < K) {
					dq.pop_front();
					cnt += a;
				}
				else if (cnt + a >= K) {
					sort(nums.begin(), nums.begin() + a, greater<int>());
					ans = nums[K - cnt - 1];
					break;
				}
			}
		}
	}
	cout << ans;

	return 0;
}