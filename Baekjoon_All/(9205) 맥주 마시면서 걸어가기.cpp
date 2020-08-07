#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

// arr[0] : house | arr[n+1] : festival
int arr[103][103];
queue<int> q;
int N;
bool visited[103] = { 0, };
bool flag;

void BFS() {
	int node;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (node == N + 1) {
			flag = true;
			break;
		}
		for (int i = 0; i < N + 2; i++) {
			if (arr[node][i] == 1 && !visited[i]) {
				visited[i] = 1;
				q.push(i);
			}
		}
	}
}

int main() {
	int T;
	int x, y;
	int temp;
	vector<pair<int, int>> pos_v;
	cin >> T;
	for (int i = 0; i < 103; i++) {
		for (int j = 0; j < 103; j++) {
			arr[i][j] = -1;
		}
	}
	for (int a = 0; a < T; a++) {
		flag = false;
		while (!q.empty()) q.pop();
		pos_v.clear();
		cin >> N;
		for (int i = 0; i < N + 2; i++) {
			cin >> x >> y;
			pos_v.push_back(make_pair(x, y));
		}
		for (int i = 0; i < N + 2; i++) {
			for (int j = i + 1; j < N + 2; j++) {
				temp = abs(pos_v[i].first - pos_v[j].first) + abs(pos_v[i].second - pos_v[j].second);
				if (temp <= 1000) {
					arr[i][j] = 1;
					arr[j][i] = 1;
				}
			}
		}

		q.push(0);
		visited[0] = 1;
		BFS();
		if (flag)
			cout << "happy\n";
		else
			cout << "sad\n";

		for (int i = 0; i < N + 2; i++) {
			for (int j = 0; j < N + 2; j++) {
				arr[i][j] = -1;
			}
		}
		for (int i = 0; i < N + 2; i++) {
			visited[i] = 0;
		}
	}



	return 0;
}