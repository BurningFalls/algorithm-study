#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int A[1001];

int main() {
	FASTIO;
	cin >> N;
	A[0] = 1;
	A[1] = 1;
	for (int i = 2; i <= N; i++) {
		int num = 1;
		while (true) {
			bool flag = true;
			for (int k = 1; i - 2 * k >= 0; k++) {
				if (num - A[i - k] == A[i - k] - A[i - 2 * k]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				break;
			}
			num++;
		}
		A[i] = num;
	}
	cout << A[N];

	return 0;
}