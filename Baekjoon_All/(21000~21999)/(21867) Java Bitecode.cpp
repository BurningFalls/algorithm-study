#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	vector<char> v;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		char x;
		cin >> x;
		if (x == 'J' || x == 'A' || x == 'V') continue;
		v.push_back(x);
	}
	int len = v.size();
	if (len == 0)
		cout << "nojava";
	else {
		FOR(i, 0, len - 1)
			cout << v[i];
	}


	return 0;
}