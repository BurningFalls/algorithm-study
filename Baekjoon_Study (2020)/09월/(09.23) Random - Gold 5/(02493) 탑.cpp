#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

pii arr[500001];
int ans[500001];
vector<pii> v;

int main() {
	FASTIO;
	int N;
	int num;
	cin >> N;
	FOR(i, 1, N) {
		cin >> num;
		arr[i] = { i, num };
	}
	FOR(i, 1, N) {
		while (!v.empty() && v.back().second < arr[i].second) {
			v.pop_back();
		}
		if (v.empty())
			ans[i] = 0;
		else
			ans[i] = v.back().first;
		v.push_back(arr[i]);
	}
	FOR(i, 1, N)
		cout << ans[i] << " ";

	return 0;
}