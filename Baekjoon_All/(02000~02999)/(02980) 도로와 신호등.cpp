#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

pii inf[1001];
int T[1001];

int main() {
	FASTIO;
	FOR(i, 1, 1000) {
		inf[i] = { -1, -1 };
		T[i] = 1;
	}
	int N, L;
	cin >> N >> L;
	FOR(i, 1, N) {
		int d, r, g;
		cin >> d >> r >> g;
		inf[d] = { r, g };
	}
	int pos = 1;
	int time = 1;
	while (pos < L) {
		if (inf[pos].first == -1 || T[pos] >= inf[pos].first) {
			pos++;
			time++;
			FOR(i, 1, L - 1) {
				if (inf[i].first == -1) continue;
				T[i] = (T[i] + 1) % (inf[i].first + inf[i].second);
			}
		}
		else {
			int tmp = inf[pos].first - T[pos] + 1;
			pos++;
			time += tmp;
			FOR(i, 1, L - 1) {
				if (inf[i].first == -1) continue;
				T[i] = (T[i] + tmp) % (inf[i].first + inf[i].second);
			}
		}
	}
	cout << time;

	return 0;
}