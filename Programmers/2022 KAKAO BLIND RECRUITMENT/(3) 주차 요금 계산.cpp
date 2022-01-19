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

map<string, string> mp;
map<string, int> time_sum;

vector<string> Split(string s) {
	string tmp = "";
	vector<string> v;
	s += ' ';
	FOR(i, 0, LEN(s) - 1) {
		if (s[i] == ' ') {
			v.push_back(tmp);
			tmp = "";
		}
		else {
			tmp += s[i];
		}
	}
	return v;
}

int Time(string t1, string t2) {
	int time1 = ((t1[0] - '0') * 10 + (t1[1] - '0')) * 60 + (t1[3] - '0') * 10 + (t1[4] - '0');
	int time2 = ((t2[0] - '0') * 10 + (t2[1] - '0')) * 60 + (t2[3] - '0') * 10 + (t2[4] - '0');
	return time2 - time1;
}

int Calc(int diff, vector<int>& fees) {
	int cost = fees[1];
	if (diff > fees[0]) {
		int tmp = (diff - fees[0]) / fees[2];
		if ((diff - fees[0]) % fees[2] != 0) {
			tmp++;
		}
		cost += tmp * fees[3];
	}
	return cost;
}

vector<int> solution(vector<int> fees, vector<string> records) {
	vector<int> answer;
	for (string s : records) {
		vector<string> tmp = Split(s);
		if (tmp[2] == "IN") {
			mp[tmp[1]] = tmp[0];
		}
		else if (tmp[2] == "OUT") {
			int timing = Time(mp[tmp[1]], tmp[0]);
			mp[tmp[1]] = "";
			time_sum[tmp[1]] += timing;
		}
	}
	for (pair<string, string> x : mp) {
		if (!x.second.empty()) {
			int timing = Time(mp[x.first], "23:59");
			time_sum[x.first] += timing;
		}
	}

	for (pair<string, int> x : time_sum) {
		answer.push_back(Calc(x.second, fees));
	}
	return answer;
}