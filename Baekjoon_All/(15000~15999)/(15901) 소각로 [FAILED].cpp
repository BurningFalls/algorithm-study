#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, M, K, Q;
deque<pair<int, int>> dq;
int arr[500001] = { 0, };
vector<int> ans;

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int num;
	int dir;
	int L, R, I, P, q, T;
	int len;
	cin >> N >> M >> K >> Q;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (dq.empty()) {
			dq.push_back(make_pair(num, 1));
		}
		else {
			if (dq.back().first != num) {
				dq.push_back(make_pair(num, 1));
			}
			else if (dq.back().first == num) {
				dq.back().second += 1;
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		if (dq.empty())
			break;
		arr[i] = dq.front().first;
		dq.front().second -= 1;
		if (dq.front().second == 0)
			dq.pop_front();
	}
	for (int i = 0; i < Q; i++) {
		cin >> dir;
		if (dir == 1) {
			cin >> L >> R;
			for (int j = L; j <= R; j++) {
				if (dq.empty())
					arr[j] = 0;
				else {
					arr[j] = dq.front().first;
					dq.front().second -= 1;
					if (dq.front().second == 0)
						dq.pop_front();
				}
			}
		}
		else if (dir == 2) {
			cin >> I;
			ans.push_back(arr[I]);
		}
		else if (dir == 3) {
			cin >> P >> q;
			if (dq.empty()) {
				dq.push_back(make_pair(P, q));
			}
			else {
				if (dq.back().first != P) {
					dq.push_back(make_pair(P, q));
				}
				else if (dq.back().first == P) {
					dq.back().second += q;
				}
			}
		}
		else if (dir == 4) {
			cin >> T;
			while (T > 0) {
				if (dq.front().second <= T) {
					T -= dq.front().second;
					dq.pop_front();
				}
				else if (dq.front().second > T) {
					dq.front().second -= T;
					T = 0;
				}
			}
		}
	}
	len = ans.size();
	for (int i = 0; i < len; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	for (int i = 1; i <= M; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}