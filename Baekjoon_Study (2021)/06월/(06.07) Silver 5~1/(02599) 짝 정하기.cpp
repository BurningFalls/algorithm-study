#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int Am, Aw, Bm, Bw, Cm, Cw;
int ans[6];

void Func(int x) {
	int tmp;
	if (x == 1) {
		tmp = min(Am, Bw);
		Am -= tmp; Bw -= tmp;
		ans[0] += tmp;
	}
	else if (x == 2) {
		tmp = min(Am, Cw);
		Am -= tmp; Cw -= tmp;
		ans[1] += tmp;
	}
	else if (x == 3) {
		tmp = min(Bm, Aw);
		Bm -= tmp; Aw -= tmp;
		ans[2] += tmp;
	}
	else if (x == 4) {
		tmp = min(Bm, Cw);
		Bm -= tmp; Cw -= tmp;
		ans[3] += tmp;
	}
	else if (x == 5) {
		tmp = min(Cm, Aw);
		Cm -= tmp; Aw -= tmp;
		ans[4] += tmp;
	}
	else if (x == 6) {
		tmp = min(Cm, Bw);
		Cm -= tmp; Bw -= tmp;
		ans[5] += tmp;
	}
}

int main() {
	FASTIO;
	cin >> N;
	int a, b, c, d, e, f;
	cin >> a >> b;
	cin >> c >> d;
	cin >> e >> f;
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	bool flag = true;
	bool ans_flag = false;
	while (flag) {
		Am = a, Aw = b, Bm = c, Bw = d, Cm = e, Cw = f;
		memset(ans, 0, sizeof(ans));
		FOR(i, 0, 5)
			Func(arr[i]);
		if ((Am || Aw || Bm || Bw || Cm || Cw) == 0) {
			cout << 1 << "\n";
			FOR(i, 0, 5) {
				cout << ans[i];
				if (i % 2 == 1)
					cout << "\n";
				else if (i % 2 == 0)
					cout << " ";
			}
			ans_flag = true;
			break;
		}
		flag = next_permutation(arr, arr + 6);
	}
	if (!ans_flag)
		cout << 0;

	return 0;
}