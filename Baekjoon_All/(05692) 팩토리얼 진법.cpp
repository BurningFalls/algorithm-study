#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int fact(int n) {
	int temp = 1;
	FOR(i, 1, n) {
		temp *= i;
	}
	return temp;
}

int main() {
	FASTIO;
	int N;
	while (true) {
		cin >> N;
		if (N == 0)
			break;
		int temp = 0;
		string s = to_string(N);
		FOR(i, 0, s.size() - 1) {
			temp += (s[i] - '0') * fact(s.size() - i);
		}
		cout << temp << "\n";
	}

	return 0;
}