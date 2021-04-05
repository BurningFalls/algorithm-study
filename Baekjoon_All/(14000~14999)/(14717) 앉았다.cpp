#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int Find_Pos(int A, int B) {
	int ans = 0;
	ROF(i, 10, 1) {
		if (A == i && B == i)
			ans = (11 - i);
	}
	if (ans == 0) {
		int tmp = (A + B) % 10;
		ans = 20 - tmp;
	}
	return ans;
}

int main() {
	FASTIO;
	int A, B;
	int usable[11];
	int pos_cnt[21] = { 0, };
	int num[21];
	FOR(i, 1, 20)
		num[i] = (i - 1) / 2 + 1;
	FOR(i, 1, 10)
		usable[i] = 2;
	cin >> A >> B;
	int player_pos = Find_Pos(A, B);
	usable[A] -= 1;
	usable[B] -= 1;
	vector<int> v;
	v.push_back(0);
	FOR(i, 1, 10) {
		if (usable[i] == 2) {
			v.push_back(i);
			v.push_back(i);
		}
		else if (usable[i] == 1) {
			v.push_back(i);
		}
	}
	FOR(i, 1, 18) {
		int a = v[i];
		if (!usable[a]) continue;
		usable[a] -= 1;
		FOR(j, i + 1, 18) {
			int b = v[j];
			if (!usable[b]) continue;
			int tmp_pos = Find_Pos(a, b);
			pos_cnt[tmp_pos]++;
		}
		usable[a] += 1;
	}
	double all_sum = 0;
	double win_sum = 0;
	FOR(i, 1, 20) {
		all_sum += pos_cnt[i];
	}
	FOR(i, player_pos + 1, 20) {
		win_sum += pos_cnt[i];
	}
	cout << fixed << setprecision(3);
	cout << win_sum / all_sum;

	return 0;
}