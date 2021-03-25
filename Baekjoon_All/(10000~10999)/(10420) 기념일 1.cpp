#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int num[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool is_Yun(int year) {
	if (year % 4 == 0) {
		if (year % 400 == 0)
			return true;
		else {
			if (year % 100 == 0)
				return false;
			else
				return true;
		}
	}
	else
		return false;
}

int main() {
	FASTIO;
	int N;
	int year = 2014;
	int month = 4;
	int day = 2;
	cin >> N;
	while (--N) {
		day++;
		bool flag = is_Yun(year);
		if ((month == 2 && day == 29 && !flag) ||
			(month == 2 && day == 30 && flag)) {
			month = 3;
			day = 1;
			continue;
		}
		if (num[month] < day) {
			month++;
			day = 1;
			if (month > 12) {
				year++;
				month = 1;
			}
		}
	}
	cout << year << "-";
	if (month < 10)
		cout << 0;
	cout << month << "-";
	if (day < 10)
		cout << 0;
	cout << day;

	return 0;
}