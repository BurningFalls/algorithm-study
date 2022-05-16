#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18

struct NODE {
	vector<string> wrong_time;
	vector<string> solve_time;
	vector<int> solve_idx;
};

map<string, NODE> mp;
vector<vector<pair<string, int>>> v(101, vector<pair<string, int>>());
map<string, int> total_score;
vector<pair<string, int>> ans;

int Calc(string wt, string st) {
	int wt_hour = (wt[0] - '0') * 10 + (wt[1] - '0');
	int wt_minute = (wt[3] - '0') * 10 + (wt[4] - '0');
	int st_hour = (st[0] - '0') * 10 + (st[1] - '0');
	int st_minute = (st[3] - '0') * 10 + (st[4] - '0');
	return (st_hour * 60 + st_minute) - (wt_hour * 60 + wt_minute);
}

bool compare(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	FASTIO;
	int N, M, P;
	cin >> N >> M >> P;
	NODE tmp_node;
	tmp_node.wrong_time = vector<string>(101, ".");
	tmp_node.solve_time = vector<string>(101, ".");
	FOR(m, 1, M) {
		string name;
		cin >> name;
		mp.insert({ name, tmp_node });
		total_score[name] = 0;
	}
	FOR(p, 1, P) {
		int num;
		string tim, name, result;
		cin >> num >> tim >> name >> result;
		if (result == "wrong") {
			if (mp[name].solve_time[num] != ".") continue;
			if (mp[name].wrong_time[num] == ".") {
				mp[name].wrong_time[num] = tim;
			}
		}
		else if (result == "solve") {
			if (mp[name].solve_time[num] == ".") {
				mp[name].solve_time[num] = tim;
			}
		}
	}

	for (pair<string, NODE> node : mp) {
		int score_sum = 0;
		string name = node.first;
		FOR(i, 1, N) {
			string wt = node.second.wrong_time[i];
			string st = node.second.solve_time[i];
			if (wt == "." && st == ".") {
				total_score[name] += M + 1;
			}
			else if (wt == "." && st != ".") {
				total_score[name] += M + 1;
			}
			else if (wt != "." && st == ".") {
				total_score[name] += M;
			}
			else if (wt != "." && st != ".") {
				v[i].push_back({ name, Calc(wt, st) });
			}
		}
	}

	FOR(i, 1, N) {
		sort(ALL(v[i]), compare);
		FOR(j, 0, LEN(v[i]) - 1) {
			string name = v[i][j].first;
			total_score[name] += (j + 1);
		}
	}

	for (pair<string, int> x : total_score) {
		ans.push_back(x);
	}

	sort(ALL(ans), compare);

	for (pair<string, int> x : ans) {
		cout << x.first << "\n";
	}

	return 0;
}