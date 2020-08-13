#include <iostream>
#include <vector>
using namespace std;

int N, L;
vector<pair<int, int>> v;
bool dir[3001] = { 0, };
bool can_jump[3001] = { 0, };

void Move() {
	for (int i = 0; i < N; i++) {
		if (dir[i] == 0) {
			if (v[i].second == L) {
				dir[i] = 1;
				v[i].first--;
				v[i].second--;
			}
			else {
				v[i].first++;
				v[i].second++;
			}
		}
		else if (dir[i] == 1) {
			if (v[i].first == 0) {
				dir[i] = 0;
				v[i].first++;
				v[i].second++;
			}
			else {
				v[i].first--;
				v[i].second--;
			}
		}
	}
}

void Check_Jump(int node) {
	for (int i = node; i < N - 1; i++) {
		if (v[i].first <= v[i + 1].second && v[i].second >= v[i + 1].first)
			can_jump[i] = 1;
		else
			can_jump[i] = 0;
	}
}

int main() {
	int l, d;
	int Time = 0;
	int loc = 0;
	int temp;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> l >> d;
		if (d == 0) {
			dir[i] = 0;
			v.push_back(make_pair(0, l));
		}
		else if (d == 1) {
			dir[i] = 1;
			v.push_back(make_pair(L - l, L));
		}
	}
	while (true) {
		Check_Jump(loc);
		while (can_jump[loc] == 1) {
			loc++;
			if (loc == N - 1)
				break;
		}
		if (loc == N - 1) {
			cout << Time;
			break;
		}
		Move();
		Time++;
	}

	return 0;
}