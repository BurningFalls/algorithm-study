#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

ll arr[100001];

int main() {
	FASTIO;
	int n;
	ll sum = 0;
	cin >> n;
	FOR(i, 0, n - 1) {
		cin >> arr[i];
		sum += arr[i];
	}
	if (n > 30)
		cout << sum - n;
	else {
		sort(arr, arr + n);
		ll idx = 1;
		ll temp1, temp2;
		while (true) {
			temp1 = pow(idx, n - 1);
			temp2 = pow(idx + 1, n - 1);
			if (temp1 <= arr[n - 1] && arr[n - 1] <= temp2)
				break;
			idx++;
		}
		ll sum1 = 0, sum2 = 0;
		ll temp3 = 1, temp4 = 1;
		FOR(i, 0, n - 1) {
			if (i != 0) {
				temp3 *= idx;
				temp4 *= (idx + 1);
			}
			sum1 += abs(temp3 - arr[i]);
			sum2 += abs(temp4 - arr[i]);
		}
		cout << min(sum1, sum2);
	}

	return 0;
}