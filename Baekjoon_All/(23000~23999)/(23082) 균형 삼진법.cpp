#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

vector<int> v;

int main() {
	FASTIO;
	int N;
	cin >> N;
	if (N == 0) {
		cout << 0;
		return 0;
	}
	bool flag = false;
	if (N < 0) {
		flag = true;
		N *= (-1);
	}
	while (N != 0) {
		v.push_back(N % 3);
		N /= 3;
	}
	bool up = false;
	FOR(i, 0, LEN(v) - 1) {
		v[i] += up;
		if (v[i] == 2) {
			v[i] = -1;
			up = true;
		}
		else if (v[i] == 3) {
			v[i] = 0;
			up = true;
		}
		else
			up = false;
	}
	if (up)
		v.push_back(1);
	if (flag) {
		FOR(i, 0, LEN(v) - 1) {
			v[i] *= (-1);
		}
	}
	ROF(i, LEN(v) - 1, 0) {
		if (v[i] == -1)
			cout << 'T';
		else
			cout << v[i];
	}

	return 0;
}