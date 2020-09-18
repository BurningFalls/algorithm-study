#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define PI 3.14159265358979
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int p1, s1;
	int s2, p2;
	cin >> p1 >> s1;
	cin >> s2 >> p2;
	if (p1 + p2 > s1 + s2)
		cout << "Persepolis";
	else if (p1 + p2 < s1 + s2)
		cout << "Esteghlal";
	else if (p1 + p2 == s1 + s2) {
		if (s1 < p2)
			cout << "Persepolis";
		else if (s1 > p2)
			cout << "Esteghlal";
		else
			cout << "Penalty";
	}

	return 0;
}