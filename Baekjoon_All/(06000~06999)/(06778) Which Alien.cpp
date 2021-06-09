#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int a, b;
	vector<string> v;
	cin >> a >> b;
	if (a >= 3 && b <= 4)
		v.push_back("TroyMartian");
	if (a <= 6 && b >= 2)
		v.push_back("VladSaturnian");
	if (a <= 2 && b <= 3)
		v.push_back("GraemeMercurian");
	for (string s : v)
		cout << s << "\n";

	return 0;
}