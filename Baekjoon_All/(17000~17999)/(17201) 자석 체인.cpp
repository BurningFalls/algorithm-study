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
	string s;
	cin >> s;
	bool flag = true;
	for (int i = 1; i < N * 2 - 1; i += 2) {
		if (s[i] == s[i + 1]) {
			flag = false;
			break;
		}
	}
	if (flag)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}