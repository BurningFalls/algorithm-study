#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

typedef struct _INF {
	int d;
	string s;
	string e;
} INF;

INF arr[50001];

bool cmp(INF A, INF B) {
	if (A.d == B.d) {
		if (A.e == B.e) {
			return A.s > B.s;
		}
		return A.e < B.e;
	}
	return A.d < B.d;
}

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(t, 1, N) {
		int M;
		cin >> M;
		FOR(i, 1, M) {
			int d;
			string s, e;
			cin >> d >> s >> e;
			arr[i] = { d, s, e };
		}
		sort(arr + 1, arr + M + 1, cmp);
		int idx = 1;
		int ans = 0;
		while (idx <= M) {
			int day = arr[idx].d;
			int cnt = 0;
			string Time = "0000";
			while (idx <= M && arr[idx].d == day) {
				if (Time <= arr[idx].s) {
					cnt++;
					Time = arr[idx].e;
				}
				idx++;
			}
			ans += cnt;
		}
		cout << "Scenario #" << t << ":\n" << ans << "\n\n";
	}


	return 0;
}