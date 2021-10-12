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
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

vector<int> cnt(1000001, 0);

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<pii> num(N);
	vector<int> NGF(N);
	FOR(i, 0, N - 1) {
		cin >> num[i].first;
		cnt[num[i].first]++;
	}
	FOR(i, 0, N - 1) {
		num[i].second = cnt[num[i].first];
	}
	vector<pii> v;
	ROF(i, N - 1, 0) {
		while (!v.empty() && v.back().second <= num[i].second) {
			v.pop_back();
		}
		if (v.empty()) {
			NGF[i] = -1;
		}
		else {
			NGF[i] = v.back().first;
		}
		v.push_back(num[i]);
	}
	FOR(i, 0, N - 1) {
		cout << NGF[i] << " ";
	}

	return 0;
}