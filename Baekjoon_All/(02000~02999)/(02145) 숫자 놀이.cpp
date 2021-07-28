#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string func(int x) {
	string s = to_string(x);
	int slen = s.size();
	while (slen > 1) {
		int sum = 0;
		FOR(i, 0, slen - 1)
			sum += (s[i] - '0');
		s = to_string(sum);
		slen = s.size();
	}
	return s;
}

int main() {
	FASTIO;
	int N;
	while (true) {
		cin >> N;
		if (N == 0)
			break;
		cout << func(N) << "\n";
	}


	return 0;
}