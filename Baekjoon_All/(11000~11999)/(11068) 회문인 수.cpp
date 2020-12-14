#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool Change(int x) {
	FOR(i, 2, 64) {
		int X = x;
		vector<int> v;
		while (X > 0) {
			v.push_back(X % i);
			X /= i;
		}
		int len = v.size();
		bool flag = true;
		FOR(i, 0, len / 2 - 1) {
			if (v[i] != v[len - 1 - i]) {
				flag = false;
				break;
			}
		}
		if (flag)
			return true;
	}
	return false;
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		if (Change(N))
			cout << 1;
		else
			cout << 0;
		cout << "\n";
	}

	return 0;
}