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
#define PI 3.14159265358979

struct NODE {
	double x;
	double y;
};

bool compare(NODE a, NODE b) {
	return a.x < b.x;
}

double Calc(NODE n1, NODE n2) {
	if (n2.x == n1.x) {
		return 0;
	}
	double a = (n2.y - n1.y) / (n2.x - n1.x);
	double b = n1.y - a * n1.x;
	double t1 = (a * a / 3) * n2.x * n2.x * n2.x + a * b * n2.x * n2.x + b * b * n2.x;
	double t2 = (a * a / 3) * n1.x * n1.x * n1.x + a * b * n1.x * n1.x + b * b * n1.x;
	return (t1 - t2) * PI;
}

int main() {
	FASTIO;
	vector<NODE> v(3);
	FOR(i, 0, 2) {
		cin >> v[i].x >> v[i].y;
	}
	sort(ALL(v), compare);
	double t1 = Calc(v[0], v[2]);
	double t2 = Calc(v[0], v[1]);
	double t3 = Calc(v[1], v[2]);
	double ans1 = t1 - (t2 + t3);
	if (ans1 < 0) {
		ans1 *= (-1);
	}
	FOR(i, 0, 2) {
		swap(v[i].x, v[i].y);
	}
	sort(ALL(v), compare);
	t1 = Calc(v[0], v[2]);
	t2 = Calc(v[0], v[1]);
	t3 = Calc(v[1], v[2]);
	double ans2 = t1 - (t2 + t3);
	if (ans2 < 0) {
		ans2 *= (-1);
	}
	cout << fixed << setprecision(6);
	cout << ans1 << " " << ans2;

	return 0;
}