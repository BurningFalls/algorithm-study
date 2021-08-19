#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<int> v;

int main() {
	FASTIO;
	int num = 1;
	int cnt = 0;
	while (cnt <= 1000) {
		if (!(num % 3 == 0 || num % 10 == 3)) {
			v.push_back(num);
			cnt++;
		}
		num++;
	}
	int T;
	cin >> T;
	while (T--) {
		int K;
		cin >> K;
		cout << v[K - 1] << "\n";
	}

	return 0;
}