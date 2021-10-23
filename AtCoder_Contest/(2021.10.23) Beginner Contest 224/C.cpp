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

pii arr[301];

int CCW(pii a, pii b, pii c) {
	int t1 = a.first * b.second + b.first * c.second + c.first * a.second;
	int t2 = b.first * a.second + c.first * b.second + a.first * c.second;
	if (t1 - t2 > 0)
		return 1;
	else if (t1 - t2 == 0)
		return 0;
	else if (t1 - t2 < 0)
		return -1;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i].first >> arr[i].second;
	}
	int total = 0;
	int cnt = 0;
	FOR(i, 1, N) {
		FOR(j, i + 1, N) {
			FOR(k, j + 1, N) {
				int ccw = CCW(arr[i], arr[j], arr[k]);
				if (ccw == 0) {
					cnt++;
				}
				total++;
			}
		}
	}
	cout << total - cnt;


	return 0;
}