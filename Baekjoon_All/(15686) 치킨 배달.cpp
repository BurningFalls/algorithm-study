#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
vector<pair<int, int>> house_pos_v;
vector<pair<int, int>> chicken_pos_v;
pair<int, int> chicken_pos[14];
int dist[101];
int city_min = 0;

void Calculate(int ch_y, int ch_x) {
	int d;
	for (int i = 0; i < house_pos_v.size(); i++) {
		d = abs(ch_y - house_pos_v[i].first) + abs(ch_x - house_pos_v[i].second);
		dist[i] = min(dist[i], d);
	}
}

void Choose(int node, int cnt) {
	int temp_dist[101] = { 0, };
	int sum = 0;
	if (cnt == M) {
		int map[7][7] = { 0, };
		for (int i = 0; i < M; i++) {
			map[chicken_pos[i].first][chicken_pos[i].second] = 1;
		}
		for (int i = 0; i < house_pos_v.size(); i++) {
			sum += dist[i];
		}
		if (city_min == 0)
			city_min = sum;
		else
			city_min = min(city_min, sum);
		return;
	}

	for (int i = 0; i < house_pos_v.size(); i++) {
		temp_dist[i] = dist[i];
	}
	for (int i = node; i < chicken_pos_v.size(); i++) {
		chicken_pos[cnt].first = chicken_pos_v[i].first;
		chicken_pos[cnt].second = chicken_pos_v[i].second;
		Calculate(chicken_pos[cnt].first, chicken_pos[cnt].second);
		Choose(i + 1, cnt + 1);
		for (int i = 0; i < house_pos_v.size(); i++) {
			dist[i] = temp_dist[i];
		}
	}
}

int main() {
	int num;
	for (int i = 0; i <= 100; i++) {
		dist[i] = 101;
	}
	cin >> N >> M;
	for (int i = 0; i < N * N; i++) {
		cin >> num;
		if (num == 1)
			house_pos_v.push_back(make_pair(i / N, i % N));
		else if (num == 2)
			chicken_pos_v.push_back(make_pair(i / N, i % N));
	}

	Choose(0, 0);

	cout << city_min;

	return 0;
}