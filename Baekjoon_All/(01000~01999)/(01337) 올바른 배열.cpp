#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N;
int arr[10001];
deque<int> dq;

int main() {
	FASTIO;
	int minimum = 5;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	int node = 1;
	while (node <= N) {
		dq.push_back(arr[node]);
		if (dq.size() == 6)
			dq.pop_front();
		int cnt = 0;
		FOR(x, dq[0], dq[0] + 4) {
			FOR(j, 0, dq.size() - 1) {
				if (x == dq[j]) {
					cnt++;
					break;
				}
			}
		}
		minimum = min(minimum, 5 - cnt);
		node++;
	}
	dq.pop_front();
	while (!dq.empty()) {
		int cnt = 0;
		FOR(x, dq[0], dq[0] + 4) {
			FOR(j, 0, dq.size() - 1) {
				if (x == dq[j]) {
					cnt++;
					break;
				}
			}
		}
		minimum = min(minimum, 5 - cnt);
		dq.pop_front();
	}
	cout << minimum;

	return 0;
}