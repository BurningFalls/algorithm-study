#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<int> v;

bool Is_Prime(int x) {
	if (x == 2)
		return true;
	FOR(i, 2, sqrt(x)) {
		if (x % i == 0)
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	FOR(i, 2, 100003) {
		if (Is_Prime(i))
			v.push_back(i);
	}
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 0; v[i] <= N; i++) {
			int cnt = 0;
			while (N != 1 && N % v[i] == 0) {
				cnt++;
				N /= v[i];
			}
			if (cnt != 0)
				cout << v[i] << " " << cnt << "\n";
			if (N == 1)
				break;
		}
	}

	return 0;
}