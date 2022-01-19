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

bool Compare(vector<int>& a, vector<int>& b) {
	FOR(i, 0, 10) {
		if (a[i] > b[i]) {
			return true;
		}
		else if (a[i] < b[i]) {
			return false;
		}
	}
	return false;
}

vector<int> solution(int n, vector<int> info) {
	vector<int> answer(11, 0);
	reverse(ALL(info));
	int max_diff = -1;
	FOR(i, 0, (1 << 11) - 1) {
		int lion_score = 0;
		int apeach_score = 0;
		int sum = 0;
		vector<int> cnt(11, 0);
		FOR(j, 0, 10) {
			if (!(i & (1 << j))) continue;
			cnt[j] = (info[j] + 1);
			sum += cnt[j];
		}
		if (sum > n) continue;
		FOR(j, 0, 10) {
			if (info[j] == 0 && cnt[j] == 0) continue;
			if (info[j] >= cnt[j]) {
				apeach_score += j;
			}
			else if (info[j] < cnt[j]) {
				lion_score += j;
			}
		}
		cnt[0] += n - sum;
		if (lion_score <= apeach_score) continue;
		if (max_diff < lion_score - apeach_score) {
			max_diff = lion_score - apeach_score;
			FOR(j, 0, 10) {
				answer[j] = cnt[j];
			}
		}
		else if (max_diff == lion_score - apeach_score) {
			if (Compare(cnt, answer)) {
				FOR(j, 0, 10) {
					answer[j] = cnt[j];
				}
			}
		}
	}
	reverse(ALL(answer));
	if (max_diff == -1) {
		answer = vector<int>(1);
		answer[0] = -1;
	}
	return answer;
}