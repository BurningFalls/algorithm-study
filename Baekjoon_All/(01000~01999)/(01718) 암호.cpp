#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	string a, b;
	getline(cin, a);
	cin >> b;
	int a_len = a.size();
	int b_len = b.size();
	FOR(i, 0, a_len - 1) {
		if (a[i] == ' ') {
			cout << ' ';
			continue;
		}
		char x = b[i % b_len];
		char y = a[i] - (x - 'a' + 1);
		if (y < 'a')
			y += 26;
		cout << y;
	}

	return 0;
}