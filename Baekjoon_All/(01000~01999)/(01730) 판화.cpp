#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
char Map[101][101];
int y, x;

void Do(char C) {
	if (C == 'U') {
		if (y == 1)
			return;
		if (Map[y][x] == '.')
			Map[y][x] = '|';
		else if (Map[y][x] == '-')
			Map[y][x] = '+';
		y -= 1;
		if (Map[y][x] == '.')
			Map[y][x] = '|';
		else if (Map[y][x] == '-')
			Map[y][x] = '+';
	}
	else if (C == 'D') {
		if (y == N)
			return;
		if (Map[y][x] == '.')
			Map[y][x] = '|';
		else if (Map[y][x] == '-')
			Map[y][x] = '+';
		y += 1;
		if (Map[y][x] == '.')
			Map[y][x] = '|';
		else if (Map[y][x] == '-')
			Map[y][x] = '+';
	}
	else if (C == 'L') {
		if (x == 1)
			return;
		if (Map[y][x] == '.')
			Map[y][x] = '-';
		else if (Map[y][x] == '|')
			Map[y][x] = '+';
		x -= 1;
		if (Map[y][x] == '.')
			Map[y][x] = '-';
		else if (Map[y][x] == '|')
			Map[y][x] = '+';
	}
	else if (C == 'R') {
		if (x == N)
			return;
		if (Map[y][x] == '.')
			Map[y][x] = '-';
		else if (Map[y][x] == '|')
			Map[y][x] = '+';
		x += 1;
		if (Map[y][x] == '.')
			Map[y][x] = '-';
		else if (Map[y][x] == '|')
			Map[y][x] = '+';
	}
}

int main() {
	FASTIO;
	string order;
	y = 1, x = 1;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			Map[i][j] = '.';
		}
	}
	cin >> order;
	int len = order.size();
	FOR(i, 0, len - 1) {
		Do(order[i]);
	}

	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cout << Map[i][j];
		}
		cout << "\n";
	}

	return 0;
}