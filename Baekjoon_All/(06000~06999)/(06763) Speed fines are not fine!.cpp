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
	if (a >= b)
		cout << "Congratulations, you are within the speed limit!";
	else {
		int ans = 0;
		if (b - a >= 1 && b - a <= 20)
			ans = 100;
		else if (b - a >= 21 && b - a <= 30)
			ans = 270;
		else
			ans = 500;
		cout << "You are speeding and your fine is $" << ans << ".";
	}
		

	return 0;
}