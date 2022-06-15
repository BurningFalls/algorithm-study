#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

struct NODE {
	int a;
	int b;
	int c;
};

int main() {
	FASTIO;
	vector<NODE> tmp;
	FOR(i, 0, 9) {
		FOR(j, i, 9) {
			FOR(k, j, 9) {
				if ((i + j + k) % 10 == 3) {
					tmp.push_back({ i, j, k });
				}
			}
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> A(N);
		vector<int> cnt(10, 0);
		FOR(i, 0, N - 1) {
			cin >> A[i];
			cnt[A[i] % 10]++;
		}
		bool flag = false;
		FOR(i, 0, LEN(tmp) - 1) {
			if (cnt[tmp[i].a]) {
				cnt[tmp[i].a]--;
				if (cnt[tmp[i].b]) {
					cnt[tmp[i].b]--;
					if (cnt[tmp[i].c]) {
						flag = true;
					}
					cnt[tmp[i].b]++;
				}
				cnt[tmp[i].a]++;
			}
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}

	return 0;
}