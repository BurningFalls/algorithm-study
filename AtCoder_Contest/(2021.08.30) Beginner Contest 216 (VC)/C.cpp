#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<char> v;

int main() {
	FASTIO;
	ll N;
	cin >> N;
	while (N) {
		if (N % 2 == 1) {
			N -= 1;
			v.push_back('A');
		}
		else if (N % 2 == 0) {
			N /= 2;
			v.push_back('B');
		}
	}
	int vlen = v.size();
	ROF(i, vlen - 1, 0)
		cout << v[i];


	return 0;
}