#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int a, b, c;
	cin >> a >> b >> c;
	int tmp = a / (b + c);
	tmp = tmp * (b + c);
	tmp = a - tmp;
	if (tmp < b)
		cout << 1;
	else
		cout << 0;


	return 0;
}