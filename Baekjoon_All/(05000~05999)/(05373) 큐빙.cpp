#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char Up[4][4];
char Down[4][4];
char Front[4][4];
char Back[4][4];
char Left[4][4];
char Right[4][4];

void Rotate_Clockwise(int x) {
	char temp[4][4];
	char temp2[4];
	if (x == 0) {
		FOR(i, 0, 2) FOR(j, 0, 2)
			temp[j][2 - i] = Up[i][j];
		FOR(i, 0, 2) FOR(j, 0, 2)
			Up[i][j] = temp[i][j];
		FOR(i, 0, 2)
			temp2[i] = Front[0][i];
		FOR(i, 0, 2)
			Front[0][i] = Right[0][i];
		FOR(i, 0, 2)
			Right[0][i] = Back[0][i];
		FOR(i, 0, 2)
			Back[0][i] = Left[0][i];
		FOR(i, 0, 2)
			Left[0][i] = temp2[i];
	}
	else if (x == 1) {
		FOR(i, 0, 2) FOR(j, 0, 2)
			temp[j][2 - i] = Down[i][j];
		FOR(i, 0, 2) FOR(j, 0, 2)
			Down[i][j] = temp[i][j];
		FOR(i, 0, 2)
			temp2[i] = Front[2][i];
		FOR(i, 0, 2)
			Front[2][i] = Left[2][i];
		FOR(i, 0, 2)
			Left[2][i] = Back[2][i];
		FOR(i, 0, 2)
			Back[2][i] = Right[2][i];
		FOR(i, 0, 2)
			Right[2][i] = temp2[i];
	}
	else if (x == 2) {
		FOR(i, 0, 2) FOR(j, 0, 2)
			temp[j][2 - i] = Front[i][j];
		FOR(i, 0, 2) FOR(j, 0, 2)
			Front[i][j] = temp[i][j];
		temp2[0] = Up[2][0], temp2[1] = Up[2][1], temp2[2] = Up[2][2];
		Up[2][0] = Left[2][2], Up[2][1] = Left[1][2], Up[2][2] = Left[0][2];
		Left[2][2] = Down[0][2], Left[1][2] = Down[0][1], Left[0][2] = Down[0][0];
		Down[0][2] = Right[0][0], Down[0][1] = Right[1][0], Down[0][0] = Right[2][0];
		Right[0][0] = temp2[0], Right[1][0] = temp2[1], Right[2][0] = temp2[2];
	}
	else if (x == 3) {
		FOR(i, 0, 2) FOR(j, 0, 2)
			temp[j][2 - i] = Back[i][j];
		FOR(i, 0, 2) FOR(j, 0, 2)
			Back[i][j] = temp[i][j];
		temp2[0] = Up[0][2], temp2[1] = Up[0][1], temp2[2] = Up[0][0];
		Up[0][2] = Right[2][2], Up[0][1] = Right[1][2], Up[0][0] = Right[0][2];
		Right[2][2] = Down[2][0], Right[1][2] = Down[2][1], Right[0][2] = Down[2][2];
		Down[2][0] = Left[0][0], Down[2][1] = Left[1][0], Down[2][2] = Left[2][0];
		Left[0][0] = temp2[0], Left[1][0] = temp2[1], Left[2][0] = temp2[2];
	}
	else if (x == 4) {
		FOR(i, 0, 2) FOR(j, 0, 2)
			temp[j][2 - i] = Left[i][j];
		FOR(i, 0, 2) FOR(j, 0, 2)
			Left[i][j] = temp[i][j];
		temp2[0] = Up[0][0], temp2[1] = Up[1][0], temp2[2] = Up[2][0];
		Up[0][0] = Back[2][2], Up[1][0] = Back[1][2], Up[2][0] = Back[0][2];
		Back[2][2] = Down[0][0], Back[1][2] = Down[1][0], Back[0][2] = Down[2][0];
		Down[0][0] = Front[0][0], Down[1][0] = Front[1][0], Down[2][0] = Front[2][0];
		Front[0][0] = temp2[0], Front[1][0] = temp2[1], Front[2][0] = temp2[2];
	}
	else if (x == 5) {
		FOR(i, 0, 2) FOR(j, 0, 2)
			temp[j][2 - i] = Right[i][j];
		FOR(i, 0, 2) FOR(j, 0, 2)
			Right[i][j] = temp[i][j];
		temp2[0] = Up[2][2], temp2[1] = Up[1][2], temp2[2] = Up[0][2];
		Up[2][2] = Front[2][2], Up[1][2] = Front[1][2], Up[0][2] = Front[0][2];
		Front[2][2] = Down[2][2], Front[1][2] = Down[1][2], Front[0][2] = Down[0][2];
		Down[2][2] = Back[0][0], Down[1][2] = Back[1][0], Down[0][2] = Back[2][0];
		Back[0][0] = temp2[0], Back[1][0] = temp2[1], Back[2][0] = temp2[2];
	}
}

void Rotate_CounterClockwise(int x) {
	char temp[4][4];
	char temp2[4];
	if (x == 0) {
		FOR(i, 0, 2) FOR(j, 0, 2)
			temp[2 - j][i] = Up[i][j];
		FOR(i, 0, 2) FOR(j, 0, 2)
			Up[i][j] = temp[i][j];
		FOR(i, 0, 2)
			temp2[i] = Front[0][i];
		FOR(i, 0, 2)
			Front[0][i] = Left[0][i];
		FOR(i, 0, 2)
			Left[0][i] = Back[0][i];
		FOR(i, 0, 2)
			Back[0][i] = Right[0][i];
		FOR(i, 0, 2)
			Right[0][i] = temp2[i];
	}
	else if (x == 1) {
		FOR(i, 0, 2) FOR(j, 0, 2)
			temp[2 - j][i] = Down[i][j];
		FOR(i, 0, 2) FOR(j, 0, 2)
			Down[i][j] = temp[i][j];
		FOR(i, 0, 2)
			temp2[i] = Front[2][i];
		FOR(i, 0, 2)
			Front[2][i] = Right[2][i];
		FOR(i, 0, 2)
			Right[2][i] = Back[2][i];
		FOR(i, 0, 2)
			Back[2][i] = Left[2][i];
		FOR(i, 0, 2)
			Left[2][i] = temp2[i];
	}
	else if (x == 2) {
		FOR(i, 0, 2) FOR(j, 0, 2)
			temp[2 - j][i] = Front[i][j];
		FOR(i, 0, 2) FOR(j, 0, 2)
			Front[i][j] = temp[i][j];
		temp2[0] = Up[2][0], temp2[1] = Up[2][1], temp2[2] = Up[2][2];
		Up[2][0] = Right[0][0], Up[2][1] = Right[1][0], Up[2][2] = Right[2][0];
		Right[0][0] = Down[0][2], Right[1][0] = Down[0][1], Right[2][0] = Down[0][0];
		Down[0][2] = Left[2][2], Down[0][1] = Left[1][2], Down[0][0] = Left[0][2];
		Left[2][2] = temp2[0], Left[1][2] = temp2[1], Left[0][2] = temp2[2];
	}
	else if (x == 3) {
		FOR(i, 0, 2) FOR(j, 0, 2)
			temp[2 - j][i] = Back[i][j];
		FOR(i, 0, 2) FOR(j, 0, 2)
			Back[i][j] = temp[i][j];
		temp2[0] = Up[0][2], temp2[1] = Up[0][1], temp2[2] = Up[0][0];
		Up[0][2] = Left[0][0], Up[0][1] = Left[1][0], Up[0][0] = Left[2][0];
		Left[0][0] = Down[2][0], Left[1][0] = Down[2][1], Left[2][0] = Down[2][2];
		Down[2][0] = Right[2][2], Down[2][1] = Right[1][2], Down[2][2] = Right[0][2];
		Right[2][2] = temp2[0], Right[1][2] = temp2[1], Right[0][2] = temp2[2];
	}
	else if (x == 4) {
		FOR(i, 0, 2) FOR(j, 0, 2)
			temp[2 - j][i] = Left[i][j];
		FOR(i, 0, 2) FOR(j, 0, 2)
			Left[i][j] = temp[i][j];
		temp2[0] = Up[0][0], temp2[1] = Up[1][0], temp2[2] = Up[2][0];
		Up[0][0] = Front[0][0], Up[1][0] = Front[1][0], Up[2][0] = Front[2][0];
		Front[0][0] = Down[0][0], Front[1][0] = Down[1][0], Front[2][0] = Down[2][0];
		Down[0][0] = Back[2][2], Down[1][0] = Back[1][2], Down[2][0] = Back[0][2];
		Back[2][2] = temp2[0], Back[1][2] = temp2[1], Back[0][2] = temp2[2];
	}
	else if (x == 5) {
		FOR(i, 0, 2) FOR(j, 0, 2)
			temp[2 - j][i] = Right[i][j];
		FOR(i, 0, 2) FOR(j, 0, 2)
			Right[i][j] = temp[i][j];
		temp2[0] = Up[2][2], temp2[1] = Up[1][2], temp2[2] = Up[0][2];
		Up[2][2] = Back[0][0], Up[1][2] = Back[1][0], Up[0][2] = Back[2][0];
		Back[0][0] = Down[2][2], Back[1][0] = Down[1][2], Back[2][0] = Down[0][2];
		Down[2][2] = Front[2][2], Down[1][2] = Front[1][2], Down[0][2] = Front[0][2];
		Front[2][2] = temp2[0], Front[1][2] = temp2[1], Front[0][2] = temp2[2];
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		FOR(i, 0, 2) FOR(j, 0, 2) {
			Up[i][j] = 'w';
			Down[i][j] = 'y';
			Front[i][j] = 'r';
			Back[i][j] = 'o';
			Left[i][j] = 'g';
			Right[i][j] = 'b';
		}
		int N;
		cin >> N;
		char dir, sign;
		FOR(i, 1, N) {
			cin >> dir >> sign;
			if (sign == '+') {
				if (dir == 'U')
					Rotate_Clockwise(0);
				else if (dir == 'D')
					Rotate_Clockwise(1);
				else if (dir == 'F')
					Rotate_Clockwise(2);
				else if (dir == 'B')
					Rotate_Clockwise(3);
				else if (dir == 'L')
					Rotate_Clockwise(4);
				else if (dir == 'R')
					Rotate_Clockwise(5);
			}
			else if (sign == '-') {
				if (dir == 'U')
					Rotate_CounterClockwise(0);
				else if (dir == 'D')
					Rotate_CounterClockwise(1);
				else if (dir == 'F')
					Rotate_CounterClockwise(2);
				else if (dir == 'B')
					Rotate_CounterClockwise(3);
				else if (dir == 'L')
					Rotate_CounterClockwise(4);
				else if (dir == 'R')
					Rotate_CounterClockwise(5);
			}
		}
		FOR(i, 0, 2) {
			FOR(j, 0, 2) {
				cout << Up[i][j];
			}
			cout << "\n";
		}
	}

	return 0;
}