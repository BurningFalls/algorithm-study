#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int row_check[10] = { 0, };
int col_check[10] = { 0, };
int square_check[10] = { 0, };
char arr[11][11];
int area[11][11];
vector<pair<int, int>> v;

void DFS(int node) {
	if (node == v.size()) {
		FOR(i, 1, 9) {
			FOR(j, 1, 9) {
				cout << arr[i][j];
			}
			cout << "\n";
		}
		exit(0);
	}
		
	int y = v[node].first;
	int x = v[node].second;
	FOR(i, 0, 8) {
		if ((row_check[y] & (1 << i)) == (1 << i)) continue;
		if ((col_check[x] & (1 << i)) == (1 << i)) continue;
		if ((square_check[area[y][x]] & (1 << i)) == (1 << i)) continue;
		arr[y][x] = '0' + i + 1;
		row_check[y] |= 1 << i;
		col_check[x] |= 1 << i;
		square_check[area[y][x]] |= 1 << i;
		DFS(node + 1);
		row_check[y] &= ~(1 << i);
		col_check[x] &= ~(1 << i);
		square_check[area[y][x]] &= ~(1 << i);
	}
}

int main() {
	FASTIO;
	FOR(i, 1, 9) {
		FOR(j, 1, 9) {
			area[i][j] = ((i - 1) / 3) * 3 + (j - 1) / 3 + 1;
		}
	}
	FOR(i, 1, 9) {
		FOR(j, 1, 9) {
			cin >> arr[i][j];
			if (arr[i][j] != '0') {
				row_check[i] |= 1 << (arr[i][j] - '1');
				col_check[j] |= 1 << (arr[i][j] - '1');
				square_check[area[i][j]] |= 1 << (arr[i][j] - '1');
			}
			else if (arr[i][j] == '0')
				v.push_back({ i, j });
		}
	}
	DFS(0);

	return 0;
}