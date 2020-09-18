#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	double x, k;
	double arr[5];
	double sum[3];
	cin >> x >> k;
	arr[0] = k / 4;
	arr[1] = k / 2;
	arr[2] = k;
	arr[3] = k * 2;
	arr[4] = k * 4;
	sum[0] = arr[0] + arr[1] + arr[2];
	sum[1] = arr[1] + arr[2] + arr[3];
	sum[2] = arr[2] + arr[3] + arr[4];
	if (sum[2] > x) {
		if (sum[1] > x) {
			if (sum[0] > x)
				cout << 0;
			else
				cout << int(sum[0] * 1000);
		}
		else
			cout << int(sum[1] * 1000);
	}
	else
		cout << int(sum[2] * 1000);

	return 0;
}