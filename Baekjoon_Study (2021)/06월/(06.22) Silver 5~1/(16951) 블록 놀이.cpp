#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

int A[1001];
int B[1001];

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N)
		cin >> A[i];
	int mini = INF;
	FOR(i, 1, N) {
		int sum = 0;
		int num = A[i] + K;
		int idx = i + 1;
		bool flag = true;
		while (idx <= N) {
			sum += (num != A[idx]);
			idx++;
			num += K;
		}
		num = A[i] - K;
		idx = i - 1;
		while (idx >= 1) {
			if (num < 1) {
				flag = false;
				break;
			}
			sum += (num != A[idx]);
			idx--;
			num -= K;
		}
		if (!flag) continue;
		mini = min(mini, sum);
	}
	cout << mini;

	return 0;
}