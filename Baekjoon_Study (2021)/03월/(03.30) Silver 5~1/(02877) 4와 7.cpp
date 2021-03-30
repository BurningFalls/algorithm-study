#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<int> v;

void Change(int x) {
	while (x != 0) {
		v.push_back(x % 2);
		x /= 2;
	}
}

int main() {
	FASTIO;
	int K;
	cin >> K;
	K += 1;
	Change(K);
	int len = v.size();
	ROF(i, len - 2, 0) {
		if (v[i] == 0)
			cout << 4;
		else if (v[i] == 1)
			cout << 7;
	}

	return 0;
}