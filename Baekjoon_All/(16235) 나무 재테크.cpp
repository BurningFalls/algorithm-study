#include <iostream>
#include <deque>
using namespace std;

int N, M, K;
int A[12][12];
int Food[12][12];
deque<int> Trees[12][12];
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void Spring_and_Summer() {
	int food;
	int node;
	int len;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			food = Food[i][j];
			node = 0;
			len = Trees[i][j].size();
			while (node < len) {
				if (food < Trees[i][j][node]) {
					break;
				}
				else {
					food -= Trees[i][j][node];
					Trees[i][j][node] += 1;
					node++;
				}
			}
			for (int k = 0; k < len - node; k++) {
				food += Trees[i][j].back() / 2;
				Trees[i][j].pop_back();
			}
			Food[i][j] = food;
		}
	}
}

void Autumn_and_Winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < Trees[i][j].size(); k++) {
				if (Trees[i][j][k] % 5 == 0) {
					for (int a = 0; a < 8; a++) {
						int ny = i + dy[a];
						int nx = j + dx[a];
						if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
						Trees[ny][nx].push_front(1);
					}
				}
			}
			Food[i][j] += A[i][j];
		}
	}
}

int main() {
	int x, y, z;
	int tree_sum = 0;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Food[i][j] = 5;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		Trees[x][y].push_back(z);
	}

	for (int t = 0; t < K; t++) {
		Spring_and_Summer();
		Autumn_and_Winter();
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			tree_sum += Trees[i][j].size();
		}
	}
	cout << tree_sum;

	return 0;
}