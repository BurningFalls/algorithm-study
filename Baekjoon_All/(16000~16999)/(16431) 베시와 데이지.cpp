#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int By, Bx, Dy, Dx, Jy, Jx;
	int ans1, ans2;
	cin >> By >> Bx;
	cin >> Dy >> Dx;
	cin >> Jy >> Jx;
	ans1 = max(abs(Bx - Jx), abs(By - Jy));
	ans2 = abs(Dx - Jx) + abs(Dy - Jy);
	if (ans1 < ans2)
		cout << "bessie";
	else if (ans1 > ans2)
		cout << "daisy";
	else if (ans1 == ans2)
		cout << "tie";

	return 0;
}