#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int including[21] = { 0, };
bool usable[26] = { 0, };
int orders_len;
vector<pair<string, int>> inf_v[11];

void Verify(int size) {
	int num = 0;
	FOR(i, 0, 25) {
		if (usable[i])
			num |= (1 << i);
	}
	if (num == 9)
		int a = 1;
	int cnt = 0;
	FOR(i, 0, orders_len - 1) {
		if ((including[i] & num) == num) {
			cnt++;
		}
	}
	if (cnt >= 2) {
		string tmp = "";
		FOR(i, 0, 25) {
			if (usable[i]) {
				char x = i + 'A';
				tmp += x;
			}
		}
		inf_v[size].push_back({ tmp, cnt });
	}
}

void Select(int size, int node, int cnt) {
	if (cnt == size) {
		Verify(size);
		return;
	}
	FOR(i, node, 25) {
		usable[i] = 1;
		Select(size, i + 1, cnt + 1);
		usable[i] = 0;
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	orders_len = orders.size();
	int course_len = course.size();
	FOR(i, 0, orders_len - 1) {
		int order_len = orders[i].size();
		FOR(j, 0, order_len - 1) {
			int tmp = orders[i][j] - 'A';
			including[i] |= (1 << tmp);
		}
	}
	FOR(i, 0, course_len - 1) {
		Select(course[i], 0, 0);
	}
	FOR(i, 2, 10) {
		int maxi = 0;
		int inf_len = inf_v[i].size();
		FOR(j, 0, inf_len - 1) {
			maxi = max(maxi, inf_v[i][j].second);
		}
		FOR(j, 0, inf_len - 1) {
			if (maxi == inf_v[i][j].second)
				answer.push_back(inf_v[i][j].first);
		}
	}
	sort(answer.begin(), answer.end());

	return answer;
}