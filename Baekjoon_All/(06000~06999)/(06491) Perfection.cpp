#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int arr[10001];

double Log(double a, double b) {
	return log10(b) / log10(a);
}

int main() {
	FASTIO;
	int N;
	while (true) {
		int ans = 0;
		cin >> N;
		if (N == 0)
			break;
		cout << N << " ";
		FOR(i, 1, N - 1) {
			if (N % i == 0)
				ans += i;
		}
		if (N > ans)
			cout << "DEFICIENT";
		else if (N == ans)
			cout << "PERFECT";
		else if (N < ans)
			cout << "ABUNDANT";
		cout << "\n";
	}

	return 0;
}