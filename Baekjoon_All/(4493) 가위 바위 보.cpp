#include <iostream>
using namespace std;

int main() {
	int T;
	int N;
	char arr[100][2];
	int win1;
	int tie;
	int lose1;
	cin >> T;
	for (int i = 0; i < T; i++) {
		win1 = 0;
		tie = 0;
		lose1 = 0;
		cin >> N;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 2; k++) {
				cin >> arr[j][k];
			}
		}
		for (int j = 0; j < N; j++) {
			if (arr[j][0] == 'R' && arr[j][1] == 'P' ||
				arr[j][0] == 'P' && arr[j][1] == 'S' ||
				arr[j][0] == 'S' && arr[j][1] == 'R')
				lose1++;
			else if (arr[j][0] == 'P' && arr[j][1] == 'R' ||
				arr[j][0] == 'S' && arr[j][1] == 'P' ||
				arr[j][0] == 'R' && arr[j][1] == 'S')
				win1++;
			else if (arr[j][0] == 'P' && arr[j][1] == 'P' ||
				arr[j][0] == 'R' && arr[j][1] == 'R' ||
				arr[j][0] == 'S' && arr[j][1] == 'S')
				tie++;
		}
		if (win1 == lose1)
			cout << "TIE\n";
		else if (win1 > lose1)
			cout << "Player 1\n";
		else if (win1 < lose1)
			cout << "Player 2\n";
	}


	return 0;
}