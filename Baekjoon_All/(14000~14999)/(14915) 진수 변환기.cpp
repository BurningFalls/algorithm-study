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
	int m, n;
	cin >> m >> n;
	if (m == 0) {
		cout << 0;
		return 0;
	}
	while (m != 0) {
		v.push_back(m % n);
		m /= n;
	} 
	int len = v.size();
	ROF(i, len - 1, 0) {
		if (v[i] >= 10) {
			char x = v[i] - 10 + 'A';
			cout << x;
		}
		else
			cout << v[i];
	}
	

	return 0;
}