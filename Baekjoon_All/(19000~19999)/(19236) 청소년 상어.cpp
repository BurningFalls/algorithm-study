#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

pii Map[5][5];
pii fish_pos[17];
bool fish_live[17];
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int shark_y = 1, shark_x = 1;
int shark_sum = 0;
int shark_dir;
int maximum = 0;
bool continue_flag = true;

void Print() {
	cout << "물고기들 상태\n";
	FOR(i, 1, 16) {
		cout << i << ":" << fish_pos[i].first << "," << fish_pos[i].second << "\n";
	}
	cout << "\n";
	cout << "shark_dir: " << shark_dir << "\n";
	cout << "shark_sum: " << shark_sum << "\n";
	FOR(i, 1, 4) {
		FOR(j, 1, 4) {
			if (i == shark_y && j == shark_x)
				cout << "s" << "," << "s";
			else
				cout << Map[i][j].first << "," << Map[i][j].second;
			cout << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void Change_seat(int fish1, int fish2) {
	int fish1_y, fish1_x, fish2_y, fish2_x;
	int fish1_dir, fish2_dir;
	fish1_y = fish_pos[fish1].first;
	fish1_x = fish_pos[fish1].second;
	fish1_dir = Map[fish1_y][fish1_x].second;
	fish2_y = fish_pos[fish2].first;
	fish2_x = fish_pos[fish2].second;
	fish2_dir = Map[fish2_y][fish2_x].second;
	Map[fish1_y][fish1_x] = { fish2, fish2_dir };
	Map[fish2_y][fish2_x] = { fish1, fish1_dir };
	fish_pos[fish1] = { fish2_y, fish2_x };
	fish_pos[fish2] = { fish1_y, fish1_x };
}

void Fish_Move() {
	if (shark_sum == 52 && shark_dir == 2)
		int a = 2;
	FOR(i, 1, 16) {
		if (!fish_live[i]) continue;
		int fish_y = fish_pos[i].first;
		int fish_x = fish_pos[i].second;
		int fish_num = i;
		int fish_dir = Map[fish_y][fish_x].second;
		FOR(j, 0, 7) {
			int new_dir = (fish_dir + j) % 8;
			int ny = fish_y + dy[new_dir];
			int nx = fish_x + dx[new_dir];
			if (ny < 1 || ny > 4 || nx < 1 || nx > 4) continue;
			if (ny == shark_y && nx == shark_x) continue;
			Map[fish_y][fish_x].second = new_dir;
			int new_fish_num = Map[ny][nx].first;
			Change_seat(fish_num, new_fish_num);
			break;
		}
	}
}

void Shark() {
	pii cur_Map[5][5];
	pii cur_fish_pos[17];
	bool flag = false;
	int cur_y = shark_y;
	int cur_x = shark_x;
	int cur_dir = shark_dir;
	int cur_sum = shark_sum;
	int t = 1;
	while (true) {
		int next_y = cur_y + dy[shark_dir] * t;
		int next_x = cur_x + dx[shark_dir] * t;
		t++;
		if (next_y < 1 || next_x < 1 || next_y > 4 || next_x > 4) break;
		if (!fish_live[Map[next_y][next_x].first]) continue;
		flag = true;
		shark_y = next_y, shark_x = next_x;
		shark_sum += Map[next_y][next_x].first;
		shark_dir = Map[next_y][next_x].second;
		fish_live[Map[next_y][next_x].first] = 0;
		FOR(i, 1, 4)
			FOR(j, 1, 4)
				cur_Map[i][j] = Map[i][j];
		FOR(i, 1, 16)
			cur_fish_pos[i] = fish_pos[i];
		Fish_Move();
		Shark();
		shark_y = cur_y, shark_x = cur_x;
		shark_sum = cur_sum;
		shark_dir = cur_dir;
		fish_live[Map[next_y][next_x].first] = 1;
		FOR(i, 1, 4)
			FOR(j, 1, 4)
				Map[i][j] = cur_Map[i][j];
		FOR(i, 1, 16)
			fish_pos[i] = cur_fish_pos[i];
	}
	if (!flag) {
		maximum = max(maximum, shark_sum);
	}
}

int main() {
	FASTIO;
	FOR(i, 1, 16)
		fish_live[i] = 1;
	FOR(i, 1, 4) {
		FOR(j, 1, 4) {
			int a, b;
			cin >> a >> b;
			Map[i][j] = { a, b - 1 };
			fish_pos[a] = { i, j };
		}
	}
	shark_sum += Map[1][1].first;
	shark_dir = Map[1][1].second;
	fish_live[Map[1][1].first] = 0;
	Fish_Move();
	Shark();
	cout << maximum;

	return 0;
}