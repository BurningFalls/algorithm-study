#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v[300001];
vector<pair<int, int>> v2;

int main() {
	int a, b;
	int D_cnt = 0;
	int G_cnt = 0;
	int temp;
	int x, y;
	int len;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		v2.push_back(make_pair(a, b));
	}
	for (int i = 1; i <= N; i++) {
		temp = v[i].size();
		if (temp <= 2) continue;
		G_cnt += temp * (temp - 1) * (temp - 2) / 6;
	}
	len = v2.size();
	for (int i = 0; i < len; i++) {
		x = v2[i].first;
		y = v2[i].second;
		D_cnt += (v[x].size() - 1) * (v[y].size() - 1);
	}
	if (D_cnt > G_cnt * 3)
		cout << "D";
	else if (D_cnt < G_cnt * 3)
		cout << "G";
	else if (D_cnt == G_cnt * 3)
		cout << "DUDUDUNGA";

	return 0;
}