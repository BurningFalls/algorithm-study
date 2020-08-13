#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v[200001];
int visited[200001] = { 0, };
int con[200001] = { 0, };
int Size[200001] = { 0, };
bool flag = false;

void BFS(int t) {
	int node, new_node;
	int len;
	for (int node = 1; node <= N; node++) {
		if (visited[node] != t) continue;
		len = Size[node];
		for (int i = 0; i < len; i++) {
			new_node = v[node][i];
			if (visited[new_node]) continue;
			con[new_node] += 1;
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int num;
	int time = 2;
	int len;
	int temp;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		while (true) {
			cin >> num;
			if (num == 0)
				break;
			v[i].push_back(num);
			Size[i]++;
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		visited[num] = 1;
	}
	while (true) {
		if (time >= 200001)
			break;
		BFS(time - 1);
		for (int i = 1; i <= N; i++) {
			if (visited[i]) continue;
			if (con[i] == 0) continue;
			len = Size[i];
			if (len % 2 == 0)
				temp = len / 2;
			else if (len % 2 == 1)
				temp = len / 2 + 1;
			if (con[i] >= temp) {
				visited[i] = time;
				flag = true;
			}
		}
		if (flag == false)
			break;
		flag = false;
		time++;
	}
	for (int i = 1; i <= N; i++) {
		cout << visited[i] - 1 << " ";
	}

	return 0;
}