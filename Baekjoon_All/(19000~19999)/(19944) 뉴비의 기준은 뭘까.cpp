#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	if (M == 1 || M == 2)
		cout << "NEWBIE!";
	else if (M <= N)
		cout << "OLDBIE!";
	else
		cout << "TLE!";


	return 0;
}