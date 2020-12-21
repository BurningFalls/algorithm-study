#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int S1, S2;
	bool flag1 = true;
	bool flag2 = true;
	int a, b;
	cin >> S1 >> S2;
	FOR(i, 1, S1) {
		cin >> a >> b;
		if (a != b)
			flag1 = false;
	}
	FOR(i, 1, S2) {
		cin >> a >> b;
		if (a != b)
			flag2 = false;
	}
	if (flag1 && flag2)
		cout << "Accepted";
	else if (!flag1)
		cout << "Wrong Answer";
	else if (flag1 && !flag2)
		cout << "Why Wrong!!!";

	return 0;
}