#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char arr[6][20001];
char num[11][6][4];

void Make_Number() {
	char zero[6][4] = { {'#', '#', '#'},
						{'#', '.', '#'},
						{'#', '.', '#'},
						{'#', '.', '#'},
						{'#', '#', '#'} };
	char one[6][4] = { {'#', '.', '.'},
						{'#', '.', '.'},
						{'#', '.', '.'},
						{'#', '.', '.'},
						{'#', '.', '.'} };
	char two[6][4] = { {'#', '#', '#'},
						{'.', '.', '#'},
						{'#', '#', '#'},
						{'#', '.', '.'},
						{'#', '#', '#'} };
	char three[6][4] = { {'#', '#', '#'},
						{'.', '.', '#'},
						{'#', '#', '#'},
						{'.', '.', '#'},
						{'#', '#', '#'} };
	char four[6][4] = { {'#', '.', '#'},
						{'#', '.', '#'},
						{'#', '#', '#'},
						{'.', '.', '#'},
						{'.', '.', '#'} };
	char five[6][4] = { {'#', '#', '#'},
						{'#', '.', '.'},
						{'#', '#', '#'},
						{'.', '.', '#'},
						{'#', '#', '#'} };
	char six[6][4] = { {'#', '#', '#'},
						{'#', '.', '.'},
						{'#', '#', '#'},
						{'#', '.', '#'},
						{'#', '#', '#'} };
	char seven[6][4] = { {'#', '#', '#'},
						{'.', '.', '#'},
						{'.', '.', '#'},
						{'.', '.', '#'},
						{'.', '.', '#'} };
	char eight[6][4] = { {'#', '#', '#'},
						{'#', '.', '#'},
						{'#', '#', '#'},
						{'#', '.', '#'},
						{'#', '#', '#'} };
	char nine[6][4] = { {'#', '#', '#'},
						{'#', '.', '#'},
						{'#', '#', '#'},
						{'.', '.', '#'},
						{'#', '#', '#'} };
	FOR(i, 0, 4) FOR(j, 0, 2) num[0][i][j] = zero[i][j];
	FOR(i, 0, 4) FOR(j, 0, 2) num[1][i][j] = one[i][j];
	FOR(i, 0, 4) FOR(j, 0, 2) num[2][i][j] = two[i][j];
	FOR(i, 0, 4) FOR(j, 0, 2) num[3][i][j] = three[i][j];
	FOR(i, 0, 4) FOR(j, 0, 2) num[4][i][j] = four[i][j];
	FOR(i, 0, 4) FOR(j, 0, 2) num[5][i][j] = five[i][j];
	FOR(i, 0, 4) FOR(j, 0, 2) num[6][i][j] = six[i][j];
	FOR(i, 0, 4) FOR(j, 0, 2) num[7][i][j] = seven[i][j];
	FOR(i, 0, 4) FOR(j, 0, 2) num[8][i][j] = eight[i][j];
	FOR(i, 0, 4) FOR(j, 0, 2) num[9][i][j] = nine[i][j];
}

int main() {
	FASTIO;
	Make_Number();
	vector<int> ans;
	int N;
	cin >> N;
	int col = 4;
	int row = N / 5 - 1;
	FOR(i, 0, col) {
		FOR(j, 0, row) {
			cin >> arr[i][j];
		}
	}
	
	int row_idx = 0;
	while (row_idx <= row) {
		while (row_idx <= row) {
			if (arr[0][row_idx] != '#')
				row_idx++;
			else
				break;
		}
		if (row_idx > row)
			break;
		int NUM = 1;
		FOR(k, 0, 9) {
			if (k == 1) continue;
			bool flag = true;
			FOR(i, 0, col) {
				FOR(j, row_idx, row_idx + 2) {
					if (arr[i][j] != num[k][i][j - row_idx]) {
						flag = false;
					}
				}
			}
			if (flag) {
				NUM = k;
				break;
			}
		}
		if (NUM == 1)
			row_idx += 2;
		else
			row_idx += 4;
		ans.push_back(NUM);
	}
	for (int x : ans)
		cout << x;


	return 0;
}