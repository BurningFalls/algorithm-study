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
	int N;
	cin >> N;
	vector<pii> input(N);
	FOR(i, 0, N - 1) {
		cin >> input[i].first >> input[i].second;
	}
	sort(ALL(input));
	vector<pii> v;
	int left = 0, right = 0;
	FOR(i, 0, N - 1) {
		if (i == 0) {
			left = input[i].first;
			right = input[i].second;
		}
		else {
			if (right >= input[i].first) {
				right = max(right, input[i].second);
			}
			else {
				v.push_back({ left, right });
				left = input[i].first;
				right = input[i].second;
			}
		}
	}
	v.push_back({ left, right });

	int max_right = 0;
	int idx = 0;
	FOR(i, 0, LEN(v) - 1) {
		if (max_right >= v[i].first) {
			idx = i;
			max_right = max(max_right, v[i].second + v[i].second - v[i].first);
		}
	}

	cout << v[idx].second;

	return 0;
}