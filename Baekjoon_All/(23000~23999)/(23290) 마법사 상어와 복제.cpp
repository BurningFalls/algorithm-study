#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int M, S;
vector<vector<vector<ll>>> Cur(5, vector<vector<ll>>(5, vector<ll>(10, 0)));
vector<vector<vector<ll>>> Next(5, vector<vector<ll>>(5, vector<ll>(10, 0)));
vector<vector<vector<bool>>> Smell(5, vector<vector<bool>>(5, vector<bool>(3, 0)));
vector<int> fdy = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
vector<int> fdx = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
vector<int> sdy = { 0, -1, 0, 1, 0 };
vector<int> sdx = { 0, 0, -1, 0, 1 };
int sy, sx;
int move_result;

ll Calc() {
	ll ans = 0;
	FOR(i, 1, 4) {
		FOR(j, 1, 4) {
			ans += Cur[i][j][9];
		}
	}
	return ans;
}

void fish_Move() {
	FOR(i, 1, 4) {
		FOR(j, 1, 4) {
			FOR(k, 1, 8) {
				if (Cur[i][j][k] == 0) continue;
				bool flag = false;
				FOR(t, 0, 7) {
					int dir = (k - t + 7) % 8 + 1;
					int ny = i + fdy[dir];
					int nx = j + fdx[dir];
					if (ny < 1 || nx < 1 || ny > 4 || nx > 4) continue;
					if (ny == sy && nx == sx) continue;
					bool tmp = (Smell[ny][nx][0] || Smell[ny][nx][1] || Smell[ny][nx][2]);
					if (tmp == true) continue;
					Next[ny][nx][dir] += Cur[i][j][k];
					Next[ny][nx][9] += Cur[i][j][k];
					flag = true;
					break;
				}
				if (!flag) {
					Next[i][j][k] += Cur[i][j][k];
					Next[i][j][9] += Cur[i][j][k];
				}
			}
		}
	}
}

void shark_Wheretogo() {
	move_result = 111;

	ll max_cnt = -1;
	ll cnt = 0;
	int ny = sy, nx = sx;
	FOR(i, 1, 4) {
		if (ny + sdy[i] < 1 || nx + sdx[i] < 1 || ny + sdy[i] > 4 || nx + sdx[i] > 4) continue;
		ny += sdy[i], nx += sdx[i];
		int t1 = Next[ny][nx][9];
		cnt += t1;
		Next[ny][nx][9] = 0;
		FOR(j, 1, 4) {
			if (ny + sdy[j] < 1 || nx + sdx[j] < 1 || ny + sdy[j] > 4 || nx + sdx[j] > 4) continue;
			ny += sdy[j], nx += sdx[j];
			int t2 = Next[ny][nx][9];
			cnt += t2;
			Next[ny][nx][9] = 0;
			FOR(k, 1, 4) {
				if (ny + sdy[k] < 1 || nx + sdx[k] < 1 || ny + sdy[k] > 4 || nx + sdx[k] > 4) continue;
				ny += sdy[k], nx += sdx[k];
				int t3 = Next[ny][nx][9];
				cnt += t3;
				Next[ny][nx][9] = 0;

				if (max_cnt < cnt) {
					max_cnt = cnt;
					move_result = 100 * i + 10 * j + k;
				}

				Next[ny][nx][9] = t3;
				cnt -= t3;
				ny -= sdy[k], nx -= sdx[k];
			}
			Next[ny][nx][9] = t2;
			cnt -= t2;
			ny -= sdy[j], nx -= sdx[j];
		}
		Next[ny][nx][9] = t1;
		cnt -= t1;
		ny -= sdy[i], nx -= sdx[i];
	}
}

void shark_Move() {
	vector<int> dir;
	while (move_result != 0) {
		dir.push_back(move_result % 10);
		move_result /= 10;
	}
	
	ROF(i, 2, 0) {
		sy += sdy[dir[i]];
		sx += sdx[dir[i]];
		if (Next[sy][sx][9] != 0) {
			Smell[sy][sx][0] = true;
		}
		FOR(j, 1, 9) {
			Next[sy][sx][j] = 0;
		}
	}
}

void smell_Remove() {
	FOR(i, 1, 4) {
		FOR(j, 1, 4) {
			Smell[i][j][2] = Smell[i][j][1];
			Smell[i][j][1] = Smell[i][j][0];
			Smell[i][j][0] = false;
		}
	}
}

void copy_Spell() {
	FOR(i, 1, 4) {
		FOR(j, 1, 4) {
			FOR(k, 1, 9) {
				Cur[i][j][k] += Next[i][j][k];
				Next[i][j][k] = 0;
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> M >> S;
	FOR(i, 1, M) {
		int fy, fx, d;
		cin >> fy >> fx >> d;
		Cur[fy][fx][d] += 1;
		Cur[fy][fx][9] += 1;
	}
	cin >> sy >> sx;

	FOR(i, 1, S) {
		fish_Move();
		shark_Wheretogo();
		shark_Move();
		smell_Remove();
		copy_Spell();
	}

	cout << Calc();

	return 0;
}