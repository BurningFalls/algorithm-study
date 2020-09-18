#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int N; // 이닝 수
int arr[51][10]; // 각 이닝의 결과
// 1:안타, 2:2루타, 3:3루타, 4:홈런, 0:아웃
int players[10] = { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 };
int visited[10] = { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 };
deque<pair<int, int>> player_dq;
deque<int> board_dq(3);
// 홈, 1루, 2루, 3루
int max_score = 0;

int Baseball_Game() {
	int out_cnt;
	int player, result;
	int score;
	score = 0;
	for (int inning = 1; inning <= N; inning++) {
		out_cnt = 0;
		for (int i = 0; i < 3; i++)
			board_dq[i] = 0;
		for (int i = 0; i < 9; i++) {
			player_dq[i].second = arr[inning][player_dq[i].first - 1];
		}
		while (true) {
			player = player_dq.front().first;
			result = player_dq.front().second;
			if (result == 0) {
				out_cnt++;
			}
			else {
				for (int j = 0; j < result; j++) {
					if (j == 0)
						board_dq.push_front(player);
					else
						board_dq.push_front(0);
					if (board_dq.back() != 0)
						score++;
					board_dq.pop_back();
				}
			}
			player_dq.push_back(make_pair(player, result));
			player_dq.pop_front();
			if (out_cnt == 3)
				break;
		}
	}
	return score;
}

void Set_Player(int cnt) {
	if (cnt == 10) {
		player_dq.clear();
		for (int i = 0; i < 9; i++)
			player_dq.push_back(make_pair(players[i + 1], 0));
		max_score = max(max_score, Baseball_Game());
		return;
	}

	for (int i = 2; i <= 9; i++) {
		if (cnt == 4) {
			Set_Player(cnt + 1);
			return;
		}
		if (visited[i]) continue;
		players[cnt] = i;
		visited[i] = 1;
		Set_Player(cnt + 1);
		visited[i] = 0;
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}

	Set_Player(1);

	cout << max_score;

	return 0;
}