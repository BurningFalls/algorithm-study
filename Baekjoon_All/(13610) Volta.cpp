#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	int a, b;
	int t1, t2;
	cin >> a >> b;
	t1 = a * b;
	t2 = (b - a) * a;
	if (t1 % t2 == 0)
		cout << t1 / t2;
	else
		cout << t1 / t2 + 1;
	
	return 0;
}