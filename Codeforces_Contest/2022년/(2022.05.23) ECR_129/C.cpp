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
#define INF int(2e9)
#define LINF ll(1e18)

bool compare(pii a, pii b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> A(N), B(N);
		FOR(i, 0, N - 1) {
			cin >> A[i];
		}
		FOR(i, 0, N - 1) {
			cin >> B[i];
		}

		vector<pii> tmp;
		FOR(i, 0, N - 1) {
			tmp.push_back({ A[i], B[i] });
		}
		sort(ALL(tmp), compare);
		bool flag = true;
		FOR(i, 1, N - 1) {
			if (tmp[i - 1].first > tmp[i].first || tmp[i - 1].second > tmp[i].second) {
				flag = false;
				break;
			}
		}

		if (!flag) {
			cout << "-1\n";
			continue;
		}

		vector<pii> ans;
		FOR(i, 0, N - 1) {
			pii minimum = { INF, INF };
			int idx = -1;
			FOR(j, i, N - 1) {
				if (A[j] <= minimum.first && B[j] <= minimum.second) {
					minimum = { A[j], B[j] };
					idx = j;
				}
			}
			if (A[i] == A[idx] && B[i] == B[idx]) continue;
			ans.push_back({ i, idx });
			swap(A[i], A[idx]);
			swap(B[i], B[idx]);
		}

		cout << LEN(ans) << "\n";
		for (pii x : ans) {
			cout << x.first + 1 << " " << x.second + 1 << "\n";
		}
	}

	return 0;
}