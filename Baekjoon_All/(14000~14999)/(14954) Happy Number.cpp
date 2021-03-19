#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int n;
	cin >> n;
	bool flag = false;
	while (true) {
		if (n == 1) {
			flag = true;
			break;
		}
		string s = to_string(n);
		int len = s.size();
		int sum = 0;
		FOR(i, 0, len - 1)
			sum += (s[i] - '0') * (s[i] - '0');
		if (sum == 4)
			break;
		n = sum;
	}
	if (flag)
		cout << "HAPPY";
	else
		cout << "UNHAPPY";

	return 0;
}