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
	cin.ignore();
	FOR(i, 1, N) {
		string s;
		getline(cin, s);
		int len = s.size();
		int sum = 0;
		FOR(j, 0, len - 1) {
			if (s[j] == ' ') continue;
			sum += (s[j] - 'A' + 1);
		}
		if (sum == 100)
			cout << "PERFECT LIFE";
		else
			cout << sum;
		cout << "\n";
	}


	return 0;
}