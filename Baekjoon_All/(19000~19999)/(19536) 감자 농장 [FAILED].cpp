#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int N, Q;
	char C;
	int x;
	map<int, int> s;
	map<int, int>::iterator iter;
	int goal;
	bool flag = 1;
	int potato_cnt = 0;
	int time = 0;
	int cur_pos;
	int R_check[2] = { 0, 0 };
	int cnt = 3;
	s.insert(make_pair(0, 0));
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> C;
		if (C == 'P')
			s.insert(make_pair(i, 2));
		else if (C == 'R')
			s.insert(make_pair(i, 1));
	}
	s.insert(make_pair(N + 1, 0));
	for (int i = 0; i < Q; i++) {
		cin >> x;
		potato_cnt = 0;
		time = 0;
		flag = 1;
		R_check[0] = 0, R_check[1] = 0;
		cur_pos = x;
		while (true) {
			if (flag == 1) {
				iter = s.upper_bound(cur_pos);
				while ((*iter).second == cnt)
					iter++;
				goal = (*iter).first;
				time += (goal - cur_pos);
				cur_pos = goal;
			}
			else if (flag == 0) {
				iter = s.lower_bound(cur_pos);
				iter--;
				while ((*iter).second == cnt)
					iter--;
				goal = (*iter).first;
				time += (cur_pos - goal);
				cur_pos = goal;
			}
			if ((*iter).second == 0)
				break;
			else if ((*iter).second >= 2) {
				potato_cnt++;
				(*iter).second = cnt;
			}
			else if ((*iter).second == 1) {
				if (flag == 1)
					R_check[0] = 1;
				else if (flag == 0)
					R_check[1] = 1;
			}
			flag = !flag;
			if (R_check[0] == 1 && R_check[1] == 1)
				break;
		}
		if (R_check[0] == 1 && R_check[1] == 1)
			cout << potato_cnt << " " << -1 << "\n";
		else
			cout << potato_cnt << " " << time << "\n";
		cnt++;
	}

	return 0;
}