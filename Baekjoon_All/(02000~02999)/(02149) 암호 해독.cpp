#include <iostream>
#include <string.h>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	char KEY[11];
	char Input_PW[101];
	char PW[101][11];
	char PLAIN[101][11];
	int KEY_length;
	int INPUT_length;
	int col, row;
	vector<pair<char, int>> p;

	cin >> KEY;
	cin >> Input_PW;
	KEY_length = strlen(KEY);
	INPUT_length = strlen(Input_PW);
	col = INPUT_length / KEY_length;
	row = KEY_length;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			PW[j][i] = Input_PW[i * col + j];
		}
	}
	for (int i = 0; i < KEY_length; i++) {
		p.push_back(make_pair(KEY[i], i + 1));
	}
	sort(p.begin(), p.end());
	for (int i = 1; i <= KEY_length; i++) {
		for (int j = 0; j < KEY_length; j++) {
			if (p[j].second == i) {
				for (int k = 0; k < col; k++) {
					PLAIN[k][i - 1] = PW[k][j];
				}
				break;
			}
		}
	}
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cout << PLAIN[i][j];
		}
	}

	return 0;
}