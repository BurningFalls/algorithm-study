#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string Create_Hori(int R, int C) {
	string ans = "";
	FOR(i, 1, R) {
		if (i % 2 == 1) {
			FOR(j, 1, C - 1)
				ans += 'R';
		}
		else if (i % 2 == 0) {
			FOR(j, 1, C - 1)
				ans += 'L';
		}
		if (i != R)
			ans += 'D';
	}
	return ans;
}

string Create_Verti(int R, int C) {
	string ans = "";
	FOR(i, 1, C) {
		if (i % 2 == 1) {
			FOR(j, 1, R - 1)
				ans += 'D';
		}
		else if (i % 2 == 0) {
			FOR(j, 1, R - 1)
				ans += 'U';
		}
		if (i != C)
			ans += 'R';
	}
	return ans;
}

int main() {
	FASTIO;
	int R, C;
	int mini = 1001;
	int miny = 0, minx = 0;
	int num;
	cin >> R >> C;
	FOR(i, 1, R) {
		FOR(j, 1, C) {
			cin >> num;
			if ((i + j) % 2 == 1) {
				if (mini > num) {
					mini = num;
					miny = i;
					minx = j;
				}
			}
		}
	}
	string ans = "";
	if (R % 2 == 1) {
		ans = Create_Hori(R, C);
	}
	else if (C % 2 == 1) {
		ans = Create_Verti(R, C);
	}
	else if (C % 2 == 0) {
		string front = "", mid = "", back = "";
		front += Create_Hori(miny - 1, C);
		if (miny - 1 >= 1)
			front += 'D';
		if ((miny - 1) % 2 == 0) {
			FOR(i, 1, (minx - 1) / 2) {
				mid += "DRUR";
			}
			mid += "DR";
			FOR(i, 1, (C - minx) / 2) {
				mid += "RURD";
			}
			back += Create_Hori(R - miny - 1, C);
			if (R - miny - 1 >= 1)
				back += 'D';
			reverse(back.begin(), back.end());
		}
		else if ((miny - 1) % 2 == 1) {
			FOR(i, 1, (C - minx) / 2) {
				mid += "DLUL";
			}
			mid += "DL";
			FOR(i, 1, (minx - 1) / 2) {
				mid += "LULD";
			}
			if (R - miny - 1 >= 1)
				back += 'D';
			back += Create_Hori(R - miny - 1, C);
		}
		ans = front + mid + back;
	}
	cout << ans;

	return 0;
}