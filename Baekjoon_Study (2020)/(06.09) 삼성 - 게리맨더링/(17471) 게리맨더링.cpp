#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define INF 987654321

int N;
int population[11];
bool visited[11] = { 0, };
bool seperate[11] = { 0, };
vector<int> connect[11];
vector<int> first_v;
vector<int> second_v;
int num_visit[11] = { 0, };
int min_difference = INF;

void DFS(int node, int x) {
	int len = connect[node].size();
	int new_node;
	num_visit[node] = 1;
	for (int i = 0; i < len; i++) {
		new_node = connect[node][i];
		if (seperate[new_node] == x) continue;
		if (num_visit[new_node]) continue;
		DFS(new_node, x);
	}
}

bool Check(int x) {
	int len;
	if (x == 1) {
		len = first_v.size();
		for (int i = 0; i < len; i++) {
			if (!num_visit[first_v[i]])
				return false;
		}
	}
	else if (x == 2) {
		len = second_v.size();
		for (int i = 0; i < len; i++) {
			if (!num_visit[second_v[i]])
				return false;
		}
	}
	return true;
}

bool Is_Possible() {
	int len;
	first_v.clear();
	second_v.clear();
	for (int i = 1; i <= N; i++) {
		if (seperate[i] == 0)
			first_v.push_back(i);
		else if (seperate[i] == 1)
			second_v.push_back(i);
	}
	len = first_v.size();
	if (len == 0)
		return false;
	len = second_v.size();
	if (len == 0)
		return false;
	for (int i = 1; i <= N; i++)
		num_visit[i] = 0;
	DFS(first_v[0], 1);
	if (!Check(1))
		return false;
	for (int i = 1; i <= N; i++)
		num_visit[i] = 0;
	DFS(second_v[0], 0);
	if (!Check(2))
		return false;
	return true;
}

int Calculate() {
	int first_sum = 0, second_sum = 0;
	int len;
	int difference = 0;
	len = first_v.size();
	for (int i = 0; i < len; i++) {
		first_sum += population[first_v[i]];
	}
	len = second_v.size();
	for (int i = 0; i < len; i++) {
		second_sum += population[second_v[i]];
	}
	difference = abs(first_sum - second_sum);
	return difference;
}

void Divide(int cnt) {
	if (cnt == N + 1) {
		if (!Is_Possible())
			return;
		min_difference = min(min_difference, Calculate());
		return;
	}

	for (int i = 0; i <= 1; i++) {
		if (visited[cnt]) continue;
		visited[cnt] = 1;
		seperate[cnt] = i;
		Divide(cnt + 1);
		visited[cnt] = 0;
	}
}

int main() {
	int cnt, num;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> population[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			cin >> num;
			connect[i].push_back(num);
		}
	}

	Divide(1);

	if (min_difference == INF)
		cout << -1;
	else
		cout << min_difference;

	return 0;
}