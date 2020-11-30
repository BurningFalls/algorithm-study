#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N;
	cin >> N;
	vector<int> v;
	if (N == 0)
		cout << 0;
	else {
		while (N != 0) {
			if (N % -2 == 0) {
				v.push_back(0);
				N /= -2;
			}
			else {
				v.push_back(1);
				N = (N - 1) / -2;
			}
		}
		int len = v.size();
		ROF(i, len - 1, 0)
			cout << v[i];
	}

	return 0;
}