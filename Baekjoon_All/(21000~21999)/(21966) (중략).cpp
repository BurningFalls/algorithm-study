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
	string S;
	cin >> N >> S;
	if (N <= 25) {
		cout << S;
		return 0;
	}
	bool is_pos = true;
	bool flag = false;
	FOR(i, 11, N - 12) {
		if (S[i] == '.') {
			flag = true;
		}
		else {
			if (flag) {
				is_pos = false;
				break;
			}
		}
	}
	if (is_pos) {
		FOR(i, 0, 10)
			cout << S[i];
		cout << "...";
		FOR(i, N - 11, N - 1)
			cout << S[i];
	}
	else if (!is_pos) {
		FOR(i, 0, 8)
			cout << S[i];
		cout << "......";
		FOR(i, N - 10, N - 1)
			cout << S[i];
	}


	return 0;
}