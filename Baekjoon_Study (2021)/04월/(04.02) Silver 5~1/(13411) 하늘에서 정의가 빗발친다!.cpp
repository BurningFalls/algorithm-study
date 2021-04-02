#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
vector<pair<int, double>> V;

bool cmp(pair<int, double> a, pair<int, double> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		int y, x, v;
		cin >> y >> x >> v;
		double t = sqrt(y * y + x * x) / v;
		V.push_back({ i, t });
	}
	sort(V.begin(), V.end(), cmp);
	for (auto n : V) {
		cout << n.first << "\n";
	}

	return 0;
}