#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int N;
	string str;
	int len;
	int Rcnt = 0;
	int Bcnt = 0;
	int Rcon_cnt_left = 0, Rcon_cnt_right = 0;
	int Bcon_cnt_left = 0, Bcon_cnt_right = 0;
	cin >> N;
	cin >> str;
	len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] == 'B')
			Bcnt++;
		else if (str[i] == 'R')
			Rcnt++;
	}

	if (str[0] == 'R') {
		Rcon_cnt_left++;
		for (int i = 1; i < len; i++) {
			if (str[i] == 'R')
				Rcon_cnt_left++;
			else
				break;
		}
	}
	else if (str[0] == 'B') {
		Bcon_cnt_left++;
		for (int i = 1; i < len; i++) {
			if (str[i] == 'B')
				Bcon_cnt_left++;
			else
				break;
		}
	}
	if (str[len - 1] == 'R') {
		Rcon_cnt_right++;
		for (int i = len - 2; i >= 0; i--) {
			if (str[i] == 'R')
				Rcon_cnt_right++;
			else
				break;
		}
	}
	else if (str[len - 1] == 'B') {
		Bcon_cnt_right++;
		for (int i = len - 2; i >= 0; i--) {
			if (str[i] == 'B')
				Bcon_cnt_right++;
			else
				break;
		}
	}

	cout << min(Rcnt - max(Rcon_cnt_left, Rcon_cnt_right), Bcnt - max(Bcon_cnt_left, Bcon_cnt_right));

	return 0;
}