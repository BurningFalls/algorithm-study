#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int a, b, c;
	int ans1, ans2, ans3;
	cin >> a >> b >> c;
	ans1 = b * 2 + c * 4;
	ans2 = a * 2 + c * 2;
	ans3 = a * 4 + b * 2;
	cout << min({ ans1, ans2, ans3 });

	return 0;
}