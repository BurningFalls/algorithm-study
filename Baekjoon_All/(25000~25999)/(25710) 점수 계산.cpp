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
	int N;
	vector<int> v;
	map<int, int> mp;
	cin >> N;
	FOR(i, 0, N - 1) {
		int num;
		cin >> num;
		mp[num]++;
	}
	for (pii x : mp) {
		v.push_back(x.first);
	}
	int maxi = 0;
	FOR(i, 0, LEN(v) - 1) {
		FOR(j, i + 1, LEN(v) - 1) {
			int tmp = v[i] * v[j];
			int sum = 0;
			while (tmp) {
				sum += tmp % 10;
				tmp /= 10;
			}
			maxi = max(maxi, sum);
		}
	}
	FOR(i, 0, LEN(v) - 1) {
		if (mp[v[i]] >= 2) {
			int tmp = v[i] * v[i];
			int sum = 0;
			while (tmp) {
				sum += tmp % 10;
				tmp /= 10;
			}
			maxi = max(maxi, sum);
		}
	}
	cout << maxi;

	return 0;
}