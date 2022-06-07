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
#define INF int(2e9)
#define LINF ll(1e18)

struct Train {
	int cur_time;
	int cur_section;
	int start_time;
	int num;
};

struct compare {
	bool operator()(const Train a, const Train b) {
		if (a.cur_time == b.cur_time) {
			if (a.start_time == b.start_time) {
				return a.num > b.num;
			}
			return a.start_time > b.start_time;
		}
		return a.cur_time > b.cur_time;
	}
};

PQ<Train, vector<Train>, compare> trains;
vector<int> section_time = { 7, 7, 8, 10 };
vector<int> section_end_time(4, -1);
vector<pii> ans;

int time_to_num(string s) {
	return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + ((s[3] - '0') * 10 + (s[4] - '0'));
}

string num_to_time(int x) {
	x %= 1440;
	int hour = x / 60;
	int minute = x % 60;
	string ti = "";
	if (hour < 10)
		ti += '0';
	ti += to_string(hour);
	ti += ':';
	if (minute < 10)
		ti += '0';
	ti += to_string(minute);
	return ti;
}

int main() {
	FASTIO;
	int H, C;
	cin >> H >> C;
	FOR(i, 1, H) {
		int num;
		string ti;
		cin >> num >> ti;
		trains.push({ time_to_num(ti), 0, time_to_num(ti), num });
	}
	FOR(i, 1, C) {
		int num;
		string ti;
		cin >> num >> ti;
		trains.push({ time_to_num(ti), 3, time_to_num(ti), num });
	}
	
	while (!trains.empty()) {
		Train train = trains.top();
		trains.pop();
		if ((train.num % 2 == 1 && train.cur_section == 4) ||
			(train.num % 2 == 0 && train.cur_section == -1)) {
			ans.push_back({ train.num, train.cur_time - 1 });
			continue;
		}
		if (section_end_time[train.cur_section] <= train.cur_time) {
			train.cur_time += section_time[train.cur_section];
			section_end_time[train.cur_section] = train.cur_time;
			train.cur_time += 1;
			if (train.num % 2 == 1) {
				train.cur_section += 1;
			}
			else if (train.num % 2 == 0) {
				train.cur_section -= 1;
			}
		}
		else {
			train.cur_time = section_end_time[train.cur_section];
		}
		trains.push(train);
	}

	sort(ALL(ans));

	for (pii x : ans) {
		cout << num_to_time(x.second) << "\n";
	}

	return 0;
}