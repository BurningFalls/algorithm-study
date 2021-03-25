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
	bool flag = false;
	FOR(i, 1, N) {
		string s;
		cin >> s;
		if (s == "anj")
			flag = true;
	}
	cout << (flag ? "构具;" : "构具?");

	return 0;
}