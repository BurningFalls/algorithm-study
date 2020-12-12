#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[21][21] = { 0, };
int ans_y = -1, ans_x = -1;

int Check_row() {
	for (int i = 0; i <= 18; i++) {
		int cnt1 = 0;
		int cnt2 = 0;
		for (int j = 0; j <= 19; j++) {
			if (arr[i][j] == 1) {
				cnt1++;
				if (cnt2 == 5) {
					ans_y = i;
					ans_x = j - 5;
					return 2;
				}
				cnt2 = 0;
			}
			else if (arr[i][j] == 2) {
				cnt2++;
				if (cnt1 == 5) {
					ans_y = i;
					ans_x = j - 5;
					return 1;
				}
				cnt1 = 0;
			}
			else if (arr[i][j] == 0) {
				if (cnt1 == 5) {
					ans_y = i;
					ans_x = j - 5;
					return 1;
				}
				if (cnt2 == 5) {
					ans_y = i;
					ans_x = j - 5;
					return 2;
				}
				cnt1 = 0;
				cnt2 = 0;
			}
		}
	}
	return 0;
}

int Check_col() {
	for (int i = 0; i <= 18; i++) {
		int cnt1 = 0;
		int cnt2 = 0;
		for (int j = 0; j <= 19; j++) {
			if (arr[j][i] == 1) {
				cnt1++;
				if (cnt2 == 5) {
					ans_y = j - 5;
					ans_x = i;
					return 2;
				}
				cnt2 = 0;
			}
			else if (arr[j][i] == 2) {
				cnt2++;
				if (cnt1 == 5) {
					ans_y = j - 5;
					ans_x = i;
					return 1;
				}
				cnt1 = 0;
			}
			else if (arr[j][i] == 0) {
				if (cnt1 == 5) {
					ans_y = j - 5;
					ans_x = i;
					return 1;
				}
				if (cnt2 == 5) {
					ans_y = j - 5;
					ans_x = i;
					return 2;
				}
				cnt1 = 0;
				cnt2 = 0;
			}
		}
	}
	return 0;
}

int Check_diag1() {
	for (int diag = 4; diag <= 18; diag++) {
		int cnt1 = 0;
		int cnt2 = 0;
		for (int i = 0; i <= diag; i++) {
			int j = diag - i;
			if (arr[i][j] == 1) {
				cnt1++;
				if (cnt2 == 5) {
					ans_y = i - 1;
					ans_x = j + 1;
					return 2;
				}
				cnt2 = 0;
			}
			else if (arr[i][j] == 2) {
				cnt2++;
				if (cnt1 == 5) {
					ans_y = i - 1;
					ans_x = j + 1;
					return 1;
				}
				cnt1 = 0;
			}
			else if (arr[i][j] == 0) {
				if (cnt1 == 5) {
					ans_y = i - 1;
					ans_x = j + 1;
					return 1;
				}
				if (cnt2 == 5) {
					ans_y = i - 1;
					ans_x = j + 1;
					return 2;
				}
				cnt1 = 0;
				cnt2 = 0;
			}
		}
		if (cnt1 == 5) {
			ans_y = diag;
			ans_x = 0;
			return 1;
		}
		if (cnt2 == 5) {
			ans_y = diag;
			ans_x = 0;
			return 2;
		}
	}
	for (int diag = 4; diag <= 18; diag++) {
		int cnt1 = 0;
		int cnt2 = 0;
		for (int i = 0; i <= diag; i++) {
			int j = diag - i;
			if (arr[18 - j][18 - i] == 1) {
				cnt1++;
				if (cnt2 == 5) {
					ans_y = 17 - j;
					ans_x = 19 - i;
					return 2;
				}
				cnt2 = 0;
			}
			else if (arr[18 - j][18 - i] == 2) {
				cnt2++;
				if (cnt1 == 5) {
					ans_y = 17 - j;
					ans_x = 19 - i;
					return 1;
				}
				cnt1 = 0;
			}
			else if (arr[18 - j][18 - i] == 0) {
				if (cnt1 == 5) {
					ans_y = 17 - j;
					ans_x = 19 - i;
					return 1;
				}
				if (cnt2 == 5) {
					ans_y = 17 - j;
					ans_x = 19 - i;
					return 2;
				}
				cnt1 = 0;
				cnt2 = 0;
			}
		}
		if (cnt1 == 5) {
			ans_y = 18;
			ans_x = 18 - diag;
			return 1;
		}
		if (cnt2 == 5) {
			ans_y = 18;
			ans_x = 18 - diag;
			return 2;
		}
	}
	return 0;
}

int Check_diag2() {
	for (int diag = 4; diag <= 18; diag++) {
		int cnt1 = 0;
		int cnt2 = 0;
		for (int i = 0; i <= diag; i++) {
			if (diag == 8 && i == 0) {
				int a = 1;
			}
			int j = diag - i;
			if (arr[i][18 - j] == 1) {
				cnt1++;
				if (cnt2 == 5) {
					ans_y = i - 5;
					ans_x = 13 - j;
					return 2;
				}
				cnt2 = 0;
			}
			else if (arr[i][18 - j] == 2) {
				cnt2++;
				if (cnt1 == 5) {
					ans_y = i - 5;
					ans_x = 13 - j;
					return 1;
				}
				cnt1 = 0;
			}
			else if (arr[i][18 - j] == 0) {
				if (cnt1 == 5) {
					ans_y = i - 5;
					ans_x = 13 - j;
					return 1;
				}
				if (cnt2 == 5) {
					ans_y = i - 5;
					ans_x = 13 - j;
					return 2;
				}
				cnt1 = 0;
				cnt2 = 0;
			}
		}
		if (cnt1 == 5) {
			ans_y = diag - 4;
			ans_x = 14;
			return 1;
		}
		if (cnt2 == 5) {
			ans_y = diag - 4;
			ans_x = 14;
			return 2;
		}
	}
	for (int diag = 4; diag <= 18; diag++) {
		int cnt1 = 0;
		int cnt2 = 0;
		for (int i = 0; i <= diag; i++) {
			int j = diag - i;
			if (arr[18 - j][i] == 1) {
				cnt1++;
				if (cnt2 == 5) {
					ans_y = 13 - j;
					ans_x = i - 5;
					return 2;
				}
				cnt2 = 0;
			}
			else if (arr[18 - j][i] == 2) {
				cnt2++;
				if (cnt1 == 5) {
					ans_y = 13 - j;
					ans_x = i - 5;
					return 1;
				}
				cnt1 = 0;
			}
			else if (arr[18 - j][i] == 0) {
				if (cnt1 == 5) {
					ans_y = 13 - j;
					ans_x = i - 5;
					return 1;
				}
				if (cnt2 == 5) {
					ans_y = 13 - j;
					ans_x = i - 5;
					return 2;
				}
				cnt1 = 0;
				cnt2 = 0;
			}
		}
		if (cnt1 == 5) {
			ans_y = 14;
			ans_x = diag - 4;
			return 1;
		}
		if (cnt2 == 5) {
			ans_y = 14;
			ans_x = diag - 4;
			return 2;
		}
	}
	return 0;
}

int Check_total() {
	int flag;
	flag = Check_row();
	if (flag != 0)
		return flag;
	flag = Check_col();
	if (flag != 0)
		return flag;
	flag = Check_diag1();
	if (flag != 0)
		return flag;
	flag = Check_diag2();
	if (flag != 0)
		return flag;
	return 0;
}

int main() {
	FASTIO;
	FOR(i, 0, 18) {
		FOR(j, 0, 18) {
			cin >> arr[i][j];
		}
	}
	int ans = Check_total();
	cout << ans << "\n";
	if (ans != 0)
		cout << ans_y + 1 << " " << ans_x + 1;

	return 0;
}