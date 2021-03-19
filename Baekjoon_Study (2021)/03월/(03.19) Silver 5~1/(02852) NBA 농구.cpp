#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int team1[2881] = { 0, };
int team2[2881] = { 0, };

void Print(int m, int s) {
	if (m < 10)
		cout << 0;
	cout << m;
	cout << ":";
	if (s < 10)
		cout << 0;
	cout << s;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int num;
		char x[5];
		cin >> num;
		FOR(j, 0, 4)
			cin >> x[j];
		int tmp = ((x[0] - '0') * 10 + (x[1] - '0')) * 60 + (x[3] - '0') * 10 + (x[4] - '0');
		if (num == 1)
			team1[tmp] = 1;
		else if (num == 2)
			team2[tmp] = 1;
	}
	FOR(i, 1, 2879) {
		team1[i] += team1[i - 1];
		team2[i] += team2[i - 1];
	}
	int ans1 = 0, ans2 = 0;
	FOR(i, 0, 2879) {
		if (team1[i] > team2[i])
			ans1++;
		else if (team1[i] < team2[i])
			ans2++;
	}
	int minute, second;
	minute = ans1 / 60;
	second = ans1 - minute * 60;
	Print(minute, second);
	cout << "\n";
	minute = ans2 / 60;
	second = ans2 - minute * 60;
	Print(minute, second);

	return 0;
}