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
	double w, d, ans;
	int idx = 1;
	while (true) {
		cin >> w >> d;
		if (w == 0 && d == 0)
			break;
		cout << "Sample #" << idx << "\n";
		ans = Log(0.5, (d / w) / 810) * 5730;
		if (ans == 0)
			ans = 0;
		else if (ans <= 10000)
			ans = round(ans / 100) * 100;
		else if (ans > 10000)
			ans = round(ans / 1000) * 1000;
		cout << "The approximate age is ";
		cout << ans;
		cout << " years.\n\n";
		idx++;
	}

	return 0;
}