#include <iostream>
using namespace std;

char map[50][50];

int first_checking(int n) {
	int cur_col;
	int cur_row;
	int count;
	int col_max = 0;
	int all_col_max = 0;
	int row_max = 0;
	int all_row_max = 0;
	for (int j = 0; j < n; j++) {
		cur_row = 0;
		while (cur_row < n - 1) {
			count = 1;
			for (int i = 1; i < n - cur_row; i++) {
				if (map[j][cur_row] == map[j][cur_row + i]) {
					count++;
				}
				else
					break;
			}
			if (row_max < count) {
				row_max = count;
			}
			cur_row++;
		}
		if (all_row_max < row_max) {
			all_row_max = row_max;
		}
	}

	for (int j = 0; j < n; j++) {
		cur_col = 0;
		while (cur_col < n - 1) {
			count = 1;
			for (int i = 1; i < n - cur_col; i++) {
				if (map[cur_col][j] == map[cur_col + i][j]) {
					count++;
				}
				else
					break;
			}
			if (col_max < count) {
				col_max = count;
			}
			cur_col++;
		}
		if (all_col_max < col_max) {
			all_col_max = col_max;
		}
	}
	if (all_row_max > all_col_max)
		return all_row_max;
	else
		return all_col_max;
}

int checking(int n, int col, int row, bool b) {
	int i, j;
	int row_count, col_count;
	int row_max = 0;
	int col_max = 0;

	if (b) {
		i = 1;
		j = 1;
		for (int k = 0; k < 2; k++) {
			col_count = 1;
			while (col - i >= 0) {
				if (map[col][row + k] == map[col - i][row + k]) {
					col_count++;
					i++;
				}
				else
					break;
			}
			while (col + j < n) {
				if (map[col][row + k] == map[col + j][row + k]) {
					col_count++;
					j++;
				}
				else
					break;
			}
			if (col_max < col_count)
				col_max = col_count;
		}
		return col_max;
	}
	else if (!b) {
		i = 1;
		j = 1;
		for (int k = 0; k < 2; k++) {
			row_count = 1;
			while (row - i >= 0) {
				if (map[col + k][row] == map[col + k][row - i]) {
					row_count++;
					i++;
				}
				else
					break;
			}
			while (row + j < n) {
				if (map[col + k][row] == map[col + k][row + j]) {
					row_count++;
					j++;
				}
				else
					break;
			}
			if (row_max < row_count)
				row_max = row_count;
		}
		return row_max;
	}
	return 0;
}

int candygame(int n) {
	char temp = ' ';
	int max = first_checking(n);
	int result = 0;
	bool is_row = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (map[i][j] != map[i][j + 1]) {
				temp = map[i][j];
				map[i][j] = map[i][j + 1];
				map[i][j + 1] = temp;
				result = checking(n, i, j, is_row);
				if (max < result) {
					max = result;
				}
				map[i][j + 1] = map[i][j];
				map[i][j] = temp;
			}
		}
	}
	is_row = false;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != map[i + 1][j]) {
				temp = map[i][j];
				map[i][j] = map[i + 1][j];
				map[i + 1][j] = temp;
				result = checking(n, i, j, is_row);
				if (max < result) {
					max = result;
				}
				map[i + 1][j] = map[i][j];
				map[i][j] = temp;
			}
		}
	}
	return max;
}



int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	cout << candygame(N) << endl;
	return 0;
}