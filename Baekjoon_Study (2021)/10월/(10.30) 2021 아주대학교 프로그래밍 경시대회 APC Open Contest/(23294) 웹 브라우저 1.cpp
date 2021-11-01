#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

int N, Q, C;
deque<int> back, front;
int cur = 0;
int capacity[2001];

int main() {
	FASTIO;
	cin >> N >> Q >> C;
	FOR(i, 1, N) {
		cin >> capacity[i];
	}
	int sum = 0;
	FOR(q, 1, Q) {
		char order;
		cin >> order;
		if (order == 'B') {
			if (back.empty()) continue;
			front.push_front(cur);
			cur = back.back();
			back.pop_back();
		}
		else if (order == 'F') {
			if (front.empty()) continue;
			back.push_back(cur);
			cur = front.front();
			front.pop_front();
		}
		else if (order == 'A') {
			int num;
			cin >> num;
			while (!front.empty()) {
				int node = front.front();
				front.pop_front();
				sum -= capacity[node];
			}
			if (cur != 0) {
				back.push_back(cur);
			}
			cur = num;
			sum += capacity[cur];
			while (!back.empty() && sum > C) {
				int node = back.front();
				back.pop_front();
				sum -= capacity[node];
			}
		}
		else if (order == 'C') {
			deque<int> tmp = back;
			back.clear();
			int prev = 0;
			FOR(i, 0, LEN(tmp) - 1) {
				if (prev == tmp[i]) {
					sum -= capacity[tmp[i]];
				}
				else if (prev != tmp[i]) {
					back.push_back(tmp[i]);
				}
				prev = tmp[i];
			}
		}
	}
	cout << cur << "\n";
	if (LEN(back) == 0) {
		cout << -1;
	}
	else {
		ROF(i, LEN(back) - 1, 0) {
			cout << back[i] << " ";
		}
	}
	cout << "\n";
	if (LEN(front) == 0) {
		cout << -1;
	}
	else {
		FOR(i, 0, LEN(front) - 1) {
			cout << front[i] << " ";
		}
	}


	return 0;
}