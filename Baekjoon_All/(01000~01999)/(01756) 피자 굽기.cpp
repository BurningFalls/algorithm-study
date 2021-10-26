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

int main() {
	FASTIO;
	int D, N;
	cin >> D >> N;
	vector<int> oven(D + 1);
	map<int, int> idx;
	FOR(i, 1, D) {
		cin >> oven[i];
		if (idx.count(oven[i])) {
			idx[oven[i]] = min(idx[oven[i]], i);
		}
		else {
			idx[oven[i]] = i;
		}
	}
	vector<pii> v;
	int mini = INF;
	for (auto it = idx.begin(); it != idx.end(); it++) {
		mini = min(mini, (*it).second);
		v.push_back({ (*it).first, mini });
	}
	vector<int> pizza(N);
	FOR(i, 0, N - 1) {
		cin >> pizza[i];
	}
	int floor = D;
	FOR(i, 0, N - 1) {
		if (pizza[i] > v.back().first) {
			floor = -1;
			break;
		}
		int left = 0, right = LEN(v) - 1;
		int lb = LEN(v) - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (v[mid].first > pizza[i]){
				right = mid - 1;
				lb = min(lb, mid);
			}
			else if (v[mid].first == pizza[i]) {
				right = mid - 1;
				lb = min(lb, mid);
			}
			else if (v[mid].first < pizza[i]) {
				left = mid + 1;
			}
		}
		if (lb == 0) {
			int tmp = min(floor, D);
			floor = tmp - 1;
		}
		else {
			lb--;
			int tmp = min(floor, v[lb].second - 1);
			floor = tmp - 1;
		}
	}
	cout << max(0, floor + 1);


	return 0;
}