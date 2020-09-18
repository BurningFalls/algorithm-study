#include <iostream>
#include <vector>
using namespace std;

int N, M;
int dice[7] = { 0, };
int ch_dice[7];
int dice_posy, dice_posx;

bool Roll(int comm) {
	switch (comm) {
	case 1:
		if (dice_posx == M - 1)
			return false;
		dice_posx++;
		ch_dice[1] = dice[4];
		ch_dice[2] = dice[2];
		ch_dice[3] = dice[1];
		ch_dice[4] = dice[6];
		ch_dice[5] = dice[5];
		ch_dice[6] = dice[3];
		break;
	case 2:
		if (dice_posx == 0)
			return false;
		dice_posx--;
		ch_dice[1] = dice[3];
		ch_dice[2] = dice[2];
		ch_dice[3] = dice[6];
		ch_dice[4] = dice[1];
		ch_dice[5] = dice[5];
		ch_dice[6] = dice[4];
		break;
	case 3:
		if (dice_posy == 0)
			return false;
		dice_posy--;
		ch_dice[1] = dice[5];
		ch_dice[2] = dice[1];
		ch_dice[3] = dice[3];
		ch_dice[4] = dice[4];
		ch_dice[5] = dice[6];
		ch_dice[6] = dice[2];
		break;
	case 4:
		if (dice_posy == N - 1)
			return false;
		dice_posy++;
		ch_dice[1] = dice[2];
		ch_dice[2] = dice[6];
		ch_dice[3] = dice[3];
		ch_dice[4] = dice[4];
		ch_dice[5] = dice[1];
		ch_dice[6] = dice[5];
		break;
	}
	for (int i = 1; i <= 6; i++) {
		dice[i] = ch_dice[i];
	}
	return true;
}

int main() {
	int K;
	int map[21][21];
	vector<int> answer;
	int command;
	cin >> N >> M >> dice_posy >> dice_posx >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> command;
		if (!Roll(command)) continue;
		if (map[dice_posy][dice_posx] == 0) {
			map[dice_posy][dice_posx] = dice[6];
		}
		else {
			dice[6] = map[dice_posy][dice_posx];
			map[dice_posy][dice_posx] = 0;
		}
		answer.push_back(dice[1]);
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}