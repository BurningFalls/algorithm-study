#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	queue<pii> q;
	int N, M;
	cin >> N >> M;
	vector<int> priority(M + 1, 0);
	FOR(i, 1, N) {
		int P, W;
		cin >> P >> W;
		q.push({ P, W });
		priority[P]++;
	}
	int prio_idx = M;
	vector<pii> stack_cap, rest_cap;
	int ans = 0;
	while (prio_idx >= 1) {
		int cnt = priority[prio_idx];
		while (cnt) {
			while (q.front().first != prio_idx) {
				ans += q.front().second;
				q.push(q.front());
				q.pop();
			}
			while (!stack_cap.empty() && stack_cap.back().first == q.front().first && stack_cap.back().second < q.front().second) {
				ans += stack_cap.back().second;
				rest_cap.push_back(stack_cap.back());
				stack_cap.pop_back();
			}
			ans += q.front().second;
			stack_cap.push_back(q.front());
			q.pop();
			while (!rest_cap.empty()) {
				ans += rest_cap.back().second;
				stack_cap.push_back(rest_cap.back());
				rest_cap.pop_back();
			}
			cnt--;
		}
		prio_idx--;
	}
	cout << ans;


	return 0;
}