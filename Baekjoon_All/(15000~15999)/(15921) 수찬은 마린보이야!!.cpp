#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int N;
	double arr[101];
	double sum = 0;
	double E = 0;
	double ans = 0;
	cin >> N;
	FOR(i, 1, N) {
		cin >> arr[i];
		sum += arr[i];
	}
	sum /= N;
	FOR(i, 1, N) {
		E += (arr[i] / N);
	}
	if (E == 0 || N == 0)
		cout << "divide by zero";
	else
		cout << fixed << setprecision(2) << sum / E;

	return 0;
}