#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char arr[3][6];

bool func() {
	FOR(i, 0, 4) {
		if (arr[0][i] == arr[1][i])
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	FOR(i, 0, 1) {
		FOR(j, 0, 4) {
			cin >> arr[i][j];
		}
	}
	if (func())
		cout << "Y";
	else
		cout << "N";

	return 0;
}