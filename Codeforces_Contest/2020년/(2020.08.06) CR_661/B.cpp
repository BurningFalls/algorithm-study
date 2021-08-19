#include <bits/stdc++.h>
using namespace std;

#define MAX 1000000001
typedef long long int ll;

int main() {
	int T;
	ll a[51];
	ll b[51];
	ll a_sum, b_sum;
	ll a_min, b_min;
	ll sum;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		a_sum = 0, b_sum = 0;
		sum = 0;
		a_min = MAX;
		b_min = MAX;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a_min = min(a_min, a[i]);
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			b_min = min(b_min, b[i]);
		}
		for (int i = 0; i < n; i++) {
			a[i] -= a_min;
			b[i] -= b_min;
			a_sum += a[i];
			b_sum += b[i];
			if (a[i] == 0 || b[i] == 0) continue;
			sum += min(a[i], b[i]);
		}
		cout << a_sum + b_sum - sum << "\n";
	}

	return 0;
}