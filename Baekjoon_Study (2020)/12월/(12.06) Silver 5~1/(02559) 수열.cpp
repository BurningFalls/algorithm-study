#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[100001];
int sum[100001] = { 0, };

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	int maximum = -10000001;
	FOR(i, K, N) {
		maximum = max(maximum, sum[i] - sum[i - K]);
	}
	cout << maximum;

	return 0;
}