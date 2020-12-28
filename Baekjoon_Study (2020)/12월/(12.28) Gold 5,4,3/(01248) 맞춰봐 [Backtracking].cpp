#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string s;
char sign[12];
int N;
int num[12];
int calc[56];
int sum[12];

bool Check(int n) {
	sum[0] = num[0];
	FOR(i, 1, n - 1) {
		sum[i] = sum[i - 1] + num[i];
	}
	int temp;
	int idx = -1;
	FOR(i, 0, n - 1) {
		FOR(j, i, n - 1) {
			idx++;
			if (i == 0)
				temp = sum[j];
			else
				temp = sum[j] - sum[i - 1];
			if (temp > 0 && s[idx] == '+') continue;
			if (temp == 0 && s[idx] == '0') continue;
			if (temp < 0 && s[idx] == '-') continue;
			return false;
		}
	}
	return true;
}

void DFS(int cnt) {
	if (cnt == N) {
		FOR(i, 0, N - 1) {
			cout << num[i] << " ";
		}
		exit(0);
		return;
	}
	FOR(i, -10, 10) {
		if (sign[cnt] == '+' && i <= 0) continue;
		if (sign[cnt] == '0' && i != 0) continue;
		if (sign[cnt] == '-' && i >= 0) continue;
		num[cnt] = i;
		if (Check(cnt))
			DFS(cnt + 1);
	}
}

int main() {
	FASTIO;
	cin >> N;
	cin >> s;
	int len = N * (N + 1) / 2;
	int idx = 0;
	FOR(i, 1, N) {
		sign[i - 1] = s[idx];
		idx += (N - i + 1);
	}

	DFS(0);

	return 0;
}