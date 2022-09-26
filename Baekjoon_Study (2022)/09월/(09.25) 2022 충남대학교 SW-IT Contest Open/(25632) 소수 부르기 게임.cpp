#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int Prime(int start, int end) {
	int cnt = 0;
	FOR(i, start, end) {
		int tmp = sqrt(i);
		bool flag = true;
		FOR(j, 2, tmp) {
			if (i % j == 0) {
				flag = false;
				break;
			}
		}
		cnt += flag;
	}
	return cnt;
}

int main() {
	FASTIO;
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	int a = Prime(A, B);
	int b = Prime(C, D);
	int c = Prime(max(A, C), min(B, D));
	if (c % 2 == 0) {
		cout << (a > b ? "yt" : "yj");
	}
	else if (c % 2 == 1) {
		cout << (a < b ? "yj" : "yt");
	}

	return 0;
}