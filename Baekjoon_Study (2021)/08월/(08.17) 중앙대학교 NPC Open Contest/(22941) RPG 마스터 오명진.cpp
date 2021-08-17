#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	ll HP1, ATK1, HP2, ATK2;
	ll P, S;
	cin >> HP1 >> ATK1 >> HP2 >> ATK2;
	cin >> P >> S;
	ll DIE1 = ((HP1 % ATK2) ? HP1 / ATK2 + 1 : HP1 / ATK2);
	ll DIE2 = ((HP2 % ATK1) ? HP2 / ATK1 + 1 : HP2 / ATK1);
	ll SKILL = (((HP2 - P) % ATK1) ? (HP2 - P) / ATK1 + 1 : (HP2 - P) / ATK1);
	if (DIE1 < SKILL)
		cout << "gg";
	else {
		HP1 -= SKILL * ATK2;
		HP2 -= SKILL * ATK1;
		if (HP2 <= 0)
			cout << "Victory!";
		else if (HP1 <= 0)
			cout << "gg";
		else {
			HP2 += S;
			DIE1 = ((HP1 % ATK2) ? HP1 / ATK2 + 1 : HP1 / ATK2);
			DIE2 = ((HP2 % ATK1) ? HP2 / ATK1 + 1 : HP2 / ATK1);
			cout << ((DIE1 < DIE2) ? "gg" : "Victory!");
		}
	}


	return 0;
}