#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int L;
	int arr[11] = { 0, };
	bool check[11] = { 0, };
	int pass[11][11] = { 0, };
	pass[1][3] = 2, pass[1][7] = 4, pass[1][9] = 5;
	pass[2][8] = 5;
	pass[3][1] = 2, pass[3][7] = 5, pass[3][9] = 6;
	pass[4][6] = 5;
	pass[6][4] = 5;
	pass[7][1] = 4, pass[7][3] = 5, pass[7][9] = 8;
	pass[8][2] = 5;
	pass[9][1] = 5, pass[9][3] = 6, pass[9][7] = 8;
	cin >> L;
	FOR(i, 1, L)
		cin >> arr[i];

	bool flag = true;
	check[arr[1]] = 1;
	FOR(i, 1, L - 1) {
		int a = arr[i];
		int b = arr[i + 1];
		if (check[b]) {
			flag = false;
			break;
		}
		if (pass[a][b] != 0) {
			if (check[pass[a][b]])
				check[b] = 1;
			else {
				flag = false;
				break;
			}
		}
		else {
			check[b] = 1;
		}
	}
	cout << (flag ? "YES" : "NO");


	return 0;
}