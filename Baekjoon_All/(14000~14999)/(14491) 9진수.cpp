#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	vector<int> v;
	while (T > 0) {
		v.push_back(T % 9);
		T /= 9;
	}
	int len = v.size();
	ROF(i, v.size() - 1, 0)
		cout << v[i];

	return 0;
}