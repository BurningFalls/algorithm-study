#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

set<int> se;

vector<int> solution(vector<int> enter, vector<int> leave) {
	vector<int> answer;
	int len = LEN(enter);
	answer = vector<int>(len, 0);
	int se_size = 0;
	int leave_idx = 0;
	FOR(i, 0, len - 1) {
		for (auto it = se.begin(); it != se.end(); it++)
			answer[(*it) - 1]++;
		answer[enter[i] - 1] += se_size;
		se.insert(enter[i]);
		se_size++;
		while (se.count(leave[leave_idx])) {
			se.erase(leave[leave_idx]);
			se_size--;
			leave_idx++;
		}
	}

	return answer;
}