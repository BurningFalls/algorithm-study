#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	string X;
	int cnt = 0;
	cin >> X;
	int len, sum;
	while (X.size() != 1) {
		len = X.size();
		sum = 0;
		FOR(i, 0, len - 1) {
			sum += (X[i] - '0');
		}
		X = to_string(sum);
		cnt++;
	}
	cout << cnt << "\n";
	if (X == "3" || X == "6" || X == "9")
		cout << "YES";
	else
		cout << "NO";

	return 0;
}