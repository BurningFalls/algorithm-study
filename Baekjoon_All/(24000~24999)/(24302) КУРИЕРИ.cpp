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

double Calc(int x) {
	double ans1 = 0, ans2 = 0;

	if (x <= 5)
		ans1 = 400;
	else if (x <= 10)
		ans1 = 700;
	else if (x <= 20)
		ans1 = 1200;
	else if (x <= 30)
		ans1 = 1700;
	else
		ans1 = 57 * x;

	if (x <= 2)
		ans2 = 90 + 90 * x;
	else if (x <= 5)
		ans2 = 100 + 85 * x;
	else if (x <= 20)
		ans2 = 125 + 80 * x;
	else if (x <= 40)
		ans2 = 325 + 70 * x;
	else
		ans2 = 925 + 55 * x;
	return min(ans1, ans2);
}

int main() {
	FASTIO;
	int a, b;
	cin >> a >> b;
	a /= 1000;
	b /= 1000;
	cout << fixed << setprecision(2);
	cout << (Calc(a) + Calc(b)) / 100;

	return 0;
}