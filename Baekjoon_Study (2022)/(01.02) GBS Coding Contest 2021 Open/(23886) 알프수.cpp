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

vector<int> v;

bool Check() {
	FOR(i, 0, LEN(v) - 1) {
		if (v[i] == 0) {
			return false;
		}
	}
	if (v[0] < 0) return false;
	if (v.back() > 0) return false;
	FOR(i, 0, LEN(v) - 2) {
		if ((v[i] > 0 && v[i + 1] > 0) ||
			(v[i] < 0 && v[i + 1] < 0)) {
			if (v[i] != v[i + 1]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	FASTIO;
	string X;
	cin >> X;
	FOR(i, 0, LEN(X) - 2) {
		v.push_back(X[i + 1] - X[i]);
	}
	cout << (Check() ? "ALPSOO" : "NON ALPSOO");


	return 0;
}