#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	int n;
	string x;
	cin >> n;
	while (n--) {
		cin >> x;
		int len = x.size();
		int num = stoi(x);
		FOR(i, 0, len - 1) {
			int mult = pow(10, i);
			double tmp = (double)num / mult;
			int ans = round(tmp);
			num = ans * mult;
		}
		cout << num << "\n";
	}

	return 0;
}