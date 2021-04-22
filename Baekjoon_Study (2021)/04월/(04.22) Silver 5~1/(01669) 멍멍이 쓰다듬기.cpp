#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int X, Y;
	cin >> X >> Y;
	int num = Y - X;
	int tmp = sqrt(num);
	int idx = tmp * 2 - 1;
	int Tmp = tmp * tmp;
	if (num == Tmp)
		cout << max(idx, 0);
	else if (Tmp + 1 <= num && num <= Tmp + tmp)
		cout << idx + 1;
	else if (Tmp + tmp + 1 <= num)
		cout << idx + 2;

	return 0;
}