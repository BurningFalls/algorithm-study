#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	string a, b, c;
	cin >> a >> b >> c;
	if ((a.find(c) != string::npos) &&
		b.find(c) != string::npos)
		cout << "YES";
	else
		cout << "NO";


	return 0;
}