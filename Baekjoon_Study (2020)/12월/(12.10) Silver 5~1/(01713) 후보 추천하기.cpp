#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

struct Pic {
	int idx = 0;
	int cnt = 0;
	int time = 0;
};

int num[1001];
Pic pic[21];
int student[101] = { 0, };
int Size = 0;

int Find() {
	int min_cnt = 1001;
	FOR(i, 1, Size) {
		min_cnt = min(min_cnt, pic[i].cnt);
	}
	vector<int> min_cnt_v;
	FOR(i, 1, Size) {
		if (pic[i].cnt == min_cnt)
			min_cnt_v.push_back(i);
	}
	int len = min_cnt_v.size();
	if (len == 1)
		return min_cnt_v[0];
	int min_time = 1001;
	FOR(i, 0, len - 1) {
		int idx = min_cnt_v[i];
		min_time = min(min_time, pic[idx].time);
	}
	FOR(i, 0, len - 1) {
		int idx = min_cnt_v[i];
		if (pic[idx].time == min_time)
			return idx;
	}
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	FOR(i, 1, M) {
		cin >> num[i];
	}
	FOR(i, 1, M) {
		if (student[num[i]] == 0) {
			if (Size == N) {
				int pos = Find();
				student[pic[pos].idx] = 0;
				student[num[i]] = pos;
				pic[pos].idx = num[i];
				pic[pos].cnt = 1;
				pic[pos].time = i;
			}
			else {
				Size++;
				student[num[i]] = Size;
				pic[Size].idx = num[i];
				pic[Size].cnt = 1;
				pic[Size].time = i;
			}
		}
		else {
			pic[student[num[i]]].cnt++;
		}
	}
	vector<int> v;
	FOR(i, 1, Size)
		v.push_back(pic[i].idx);
	sort(v.begin(), v.end());
	int len = v.size();
	FOR(i, 0, len - 1)
		cout << v[i] << " ";

	return 0;
}