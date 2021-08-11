#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	while (true) {
		string s;
		cin >> s;
		if (s == "#")
			break;
		int len = s.size();
		int sum = 0;
		FOR(i, 0, len - 1) {
			int tmp = s[len - i - 1] - '0';
			tmp *= (i + 2);
			sum += tmp;
		}
		sum = sum % 11;
		sum = 11 - sum;
		cout << s << " -> ";
		if (sum == 10)
			cout << "Rejected";
		else if (sum == 11)
			cout << 0;
		else
			cout << sum;
		cout << "\n";
	}


	return 0;
}