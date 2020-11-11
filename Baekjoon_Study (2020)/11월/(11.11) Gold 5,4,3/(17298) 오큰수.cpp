#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[1000001];
int ans[1000001];

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	vector<pii> v;
	FOR(i, 1, N) {
		if (v.empty()) {
			v.push_back({ i, arr[i] });
			continue;
		}
		while (!v.empty() && v.back().second < arr[i]) {
			ans[v.back().first] = arr[i];
			v.pop_back();
		}
		v.push_back({ i, arr[i] });
	}
	while (!v.empty()) {
		ans[v.back().first] = -1;
		v.pop_back();
	}
	FOR(i, 1, N)
		cout << ans[i] << " ";

	return 0;
}