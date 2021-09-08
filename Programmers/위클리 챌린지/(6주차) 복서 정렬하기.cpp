#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

struct NODE {
	pii win_rate;
	int win_higher_cnt = 0;
	int my_weight;
	int idx;
};

vector<NODE> boxer;

bool cmp(NODE a, NODE b) {
	int frA = a.win_rate.first * b.win_rate.second;
	int frB = a.win_rate.second * b.win_rate.first;
	if (frA == frB) {
		if (a.win_higher_cnt == b.win_higher_cnt) {
			if (a.my_weight == b.my_weight) {
				return a.idx < b.idx;
			}
			return a.my_weight > b.my_weight;
		}
		return a.win_higher_cnt > b.win_higher_cnt;
	}
	return frA > frB;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
	vector<int> answer;
	int len = LEN(weights);
	FOR(i, 0, len - 1) {
		int game_cnt = 0;
		int win_cnt = 0;
		int wh_cnt = 0;
		FOR(j, 0, len - 1) {
			if (head2head[i][j] == 'N') continue;
			game_cnt++;
			if (head2head[i][j] == 'W') {
				win_cnt++;
				if (weights[i] < weights[j])
					wh_cnt++;
			}
		}
		boxer.push_back({ {win_cnt, game_cnt}, wh_cnt, weights[i], i + 1 });
	}

	sort(boxer.begin(), boxer.end(), cmp);

	FOR(i, 0, len - 1)
		answer.push_back(boxer[i].idx);

	return answer;
}