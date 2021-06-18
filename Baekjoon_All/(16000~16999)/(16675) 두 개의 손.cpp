#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int Win(char a, char b) {
	if (a == 'S') {
		if (b == 'S')
			return 0;
		else if (b == 'R')
			return -1;
		else if (b == 'P')
			return 1;
	}
	else if (a == 'R') {
		if (b == 'S')
			return 1;
		else if (b == 'R')
			return 0;
		else if (b == 'P')
			return -1;
	}
	else if (a == 'P') {
		if (b == 'S')
			return -1;
		else if (b == 'R')
			return 1;
		else if (b == 'P')
			return 0;
	}
}

int main() {
	FASTIO;
	char ML, MR, TL, TR;
	cin >> ML >> MR >> TL >> TR;
	if ((Win(ML, TL) + Win(ML, TR)) >= 2 || (Win(MR, TL) + Win(MR, TR)) >= 2)
		cout << "MS";
	else if ((Win(TL, ML) + Win(TL, MR)) >= 2 || (Win(TR, ML) + Win(TR, MR)) >= 2)
		cout << "TK";
	else
		cout << "?";


	return 0;
}