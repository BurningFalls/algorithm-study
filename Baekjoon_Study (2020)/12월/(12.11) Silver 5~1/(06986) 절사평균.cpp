#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

double arr[100001];

int main() {
	FASTIO;
	int N, K;
	cin >> N >> K;
	FOR(i, 1, N)
		cin >> arr[i];
	sort(arr + 1, arr + N + 1);
	double sum1 = 0, sum2 = 0;
	FOR(i, K + 1, N - K)
		sum1 += arr[i];
	sum2 = sum1;
	sum1 /= (double)N - 2 * (double)K;
	sum2 += arr[K + 1] * K;
	sum2 += arr[N - K] * K;
	sum2 /= N;
	printf("%.2lf\n", sum1 + 0.00000001);
	printf("%.2lf", sum2 + 0.00000001);

	return 0;
}