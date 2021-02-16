#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>

int main() {
	int A, B, C, N;
	cin >> A >> B >> C >> N;
	int a, b, c;
	a = N / A;
	b = N / B;
	c = N / C;
	bool flag = false;
	FOR(i, 0, a) {
		FOR(j, 0, b) {
			FOR(k, 0, c) {
				if (A * i + B * j + C * k == N) {
					flag = true;
					break;
				}
			}
		}
	}
	cout << flag;

	return 0;
}