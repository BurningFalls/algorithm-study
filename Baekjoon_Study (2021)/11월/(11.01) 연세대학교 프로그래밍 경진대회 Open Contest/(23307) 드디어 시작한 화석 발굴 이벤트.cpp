#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";

struct NODE {
	int midy;
	int midx;
	int len;
	string dir;
};

bool compare(NODE a, NODE b) {
	if (a.midy == b.midy)
		return a.midx < b.midx;
	return a.midy < b.midy;
}

int N;
char Map[1251][1251];
bool visited[1251][1251] = { 0, };
vector<NODE> ans;

void Check(int sy, int sx) {
	int y = sy, x = sx;
	int cnt1 = 0, cnt2 = 0;
	while (y <= N && Map[y][x] == '#') {
		y++;
		cnt1++;
	}
	y = sy, x = sx;
	while (x <= N && Map[y][x] == '#') {
		x++;
		cnt2++;
	}
	string dir = "";
	int len = 0, midy = 0, midx = 0;
	if (cnt1 >= 5 && (cnt1 - 1) % 4 == 0 && cnt2 == 1) {
		dir = "UL";
		len = cnt1;
	}
	else if (cnt1 >= 5 && (cnt1 - 1) % 4 == 0 && cnt2 >= 3 && (cnt2 + 1) % 4 == 0) {
		dir = "UR";
		len = cnt1;
	}
	else if (cnt1 == 1 && cnt2 >= 5 && (cnt2 - 1) % 4 == 0) {
		dir = "LU";
		len = cnt2;
	}
	else if (cnt1 >= 3 && (cnt1 + 1) % 4 == 0 && cnt2 >= 5 && (cnt2 - 1) % 4 == 0) {
		dir = "LD";
		len = cnt2;
	}
	else if (cnt1 >= 5 && (cnt1 - 1) % 4 == 0 && cnt2 >= 5 && (cnt2 - 1) % 4 == 0) {
		len = cnt1;
		y = sy + len - 1;
		x = sx + len - 1;
		int cnt3 = 0, cnt4 = 0;
		int ny = y, nx = x;
		while (ny >= 1 && Map[ny][nx] == '#') {
			ny--;
			cnt3++;
		}
		ny = y, nx = x;
		while (nx >= 1 && Map[ny][nx] == '#') {
			nx--;
			cnt4++;
		}
		if (cnt3 >= 5 && (cnt3 - 1) % 4 == 0 && cnt4 == 1) {
			dir = "DR";
		}
		else if (cnt3 >= 5 && (cnt3 - 1) % 4 == 0 && cnt4 >= 3 && (cnt4 + 1) % 4 == 0) {
			dir = "DL";
		}
		else if (cnt3 == 1 && cnt4 >= 5 && (cnt4 - 1) % 4 == 0) {
			dir = "RD";
		}
		else if (cnt3 >= 3 && (cnt3 + 1) % 4 == 0 && cnt4 >= 5 && (cnt4 - 1) % 4 == 0) {
			dir = "RU";
		}
	}
	midy = sy + len / 2;
	midx = sx + len / 2;
	ans.push_back({ midy, midx, len, dir });
	FOR(i, sy, sy + len - 1) {
		FOR(j, sx, sx + len - 1) {
			visited[i][j] = 1;
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
		}
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (Map[i][j] == '.') continue;
			if (visited[i][j]) continue;
			Check(i, j);
		}
	}
	sort(ALL(ans), compare);
	cout << LEN(ans) << "\n";
	for (NODE x : ans) {
		cout << x.midy << " " << x.midx << " " << x.len << " " << x.dir << "\n";
	}

	return 0;
}