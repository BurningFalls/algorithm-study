#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int N, M, T;
deque<int> dq[51];
queue<pair<int, int>> q;
int visited[51][51] = { 0, };
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

void Lefting(int x, int k) {
	int add = x;
	while (x <= N) {
		for (int i = 0; i < k; i++) {
			dq[x].push_back(dq[x].front());
			dq[x].pop_front();
		}
		x += add;
	}
}

void Righting(int x, int k) {
	int add = x;
	while (x <= N) {
		for (int i = 0; i < k; i++) {
			dq[x].push_front(dq[x].back());
			dq[x].pop_back();
		}
		x += add;
	}
}

void Rotate(int x, int d, int k) {
	int lefting = 0, righting = 0;
	if (d == 0) {
		righting = k;
		lefting = M - k;
	}
	else if (d == 1) {
		lefting = k;
		righting = M - k;
	}
	if (lefting >= righting)
		Righting(x, righting);
	else if (lefting < righting)
		Lefting(x, lefting);
}

bool BFS() {
	int y, x, ny, nx;
	int cnt = 0;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 1 || ny > N) continue;
			if (nx == -1) nx = M - 1;
			else if (nx == M) nx = 0;
			if (visited[ny][nx]) continue;
			if (dq[y][x] != dq[ny][nx]) continue;
			visited[ny][nx] = 1;
			q.push(make_pair(ny, nx));
			cnt++;
		}
	}
	if (cnt)
		return true;
	else
		return false;
}

// return 0: 수가 하나도 없음
// return 1: 수가 있고, 인접하면서 같은 수가 없음
// return 2: 수가 있고, 인접하면서 같은 수가 있음
int Erase() {
	int zero_cnt = 0;
	int one_cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (dq[i][j] == 0) {
				visited[i][j] = 2;
				zero_cnt++;
				continue;
			}
			if (visited[i][j]) continue;
			visited[i][j] = 1;
			q.push(make_pair(i, j));
			if (!BFS())
				visited[i][j] = 2;
		}
	}

	if (zero_cnt == N * M)
		return 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 1) {
				one_cnt++;
				dq[i][j] = 0;
			}
		}
	}

	if (one_cnt == 0)
		return 1;

	return 2;
}

void Renewal() {
	double avg = 0;
	int num_cnt = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (dq[i][j] == 0) continue;
			avg += dq[i][j];
			num_cnt++;
		}
	}
	avg /= num_cnt;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (dq[i][j] == 0) continue;
			if (dq[i][j] > avg)
				dq[i][j] -= 1;
			else if (dq[i][j] < avg)
				dq[i][j] += 1;
		}
	}
}

int main() {
	int num;
	int x, d, k;
	int sum = 0;
	int flag;
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num;
			dq[i].push_back(num);
		}
	}
	for (int i = 0; i < T; i++) {
		cin >> x >> d >> k;
		Rotate(x, d, k);
		flag = Erase();
		if (flag == 0)
			break;
		else if (flag == 1)
			Renewal();
		else if (flag == 2)
			continue;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			sum += dq[i][j];
		}
	}

	cout << sum;

	return 0;
}