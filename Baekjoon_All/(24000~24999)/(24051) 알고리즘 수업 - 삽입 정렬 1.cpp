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
#define INF 2e9
#define LINF 1e18

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	FOR(i, 0, N - 1) {
		cin >> A[i];
	}
	int cnt = 0;
	int num = 0;
	FOR(i, 1, N - 1) {
		int loc = i - 1;
		int newItem = A[i];
		bool flag = false;
		while (0 <= loc && newItem < A[loc]) {
			A[loc + 1] = A[loc];
			loc--;
			cnt++;
			if (cnt == K) {
				num = A[loc + 1];
				flag = true;
				break;
			}
		}
		if (flag) break;
		if (loc + 1 != i) {
			A[loc + 1] = newItem;
			cnt++;
			if (cnt == K) {
				num = newItem;
				break;
			}
		}
	}
	
	cout << (num == 0 ? -1 : num);

	return 0;
}