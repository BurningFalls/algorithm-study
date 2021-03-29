#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

double N;
int arr[300001];

int main() {
	FASTIO;
	cin >> N;
	if (N == 0) {
		cout << 0;
		return 0;
	}
	FOR(i, 1, N) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + int(N) + 1);
	int tmp = round(N * 0.15);
	int sum = 0;
	FOR(i, 1 + tmp, N - tmp) {
		sum += arr[i];
	}
	double result = sum / (N - tmp * 2);
	cout << round(result);


	return 0;
}