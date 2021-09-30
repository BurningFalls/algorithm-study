#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	char arr[5];
	FOR(i, 0, 4)
		cin >> arr[i];
	int hour = (arr[0] - '0') * 10 + (arr[1] - '0');
	int minute = (arr[3] - '0') * 10 + (arr[4] - '0');
	int cnt = 0;
	while (true) {
		if ((hour >= 7 && hour < 10) || (hour >= 15 && hour < 19))
			cnt += 1;
		else
			cnt += 2;
		minute += 20;
		if (minute == 60) {
			minute = 0;
			hour++;
		}
		if (cnt >= 12)
			break;
	}
	if (cnt == 13) {
		minute -= 10;
		if (minute < 0) {
			hour--;
			minute += 60;
		}
	}
	if (hour >= 24)
		hour -= 24;
	if (hour < 10)
		cout << 0;
	cout << hour;
	cout << ":";
	if (minute < 10)
		cout << 0;
	cout << minute;

	return 0;
}