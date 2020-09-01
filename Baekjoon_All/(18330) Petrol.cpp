#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int a, b;
	cin >> a >> b;
	int temp = 60 + b;
	if (a <= temp)
		cout << a * 1500;
	else
		cout << temp * 1500 + (a - temp) * 3000;

	return 0;
}