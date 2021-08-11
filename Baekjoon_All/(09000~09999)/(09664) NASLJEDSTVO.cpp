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
	cin >> a >> b;
	int tmp = (b * a) / (a - 1);
	if ((b * a) % (a - 1) == 0)
		cout << tmp - 1 << " " << tmp;
	else
		cout << tmp << " " << tmp;


	return 0;
}