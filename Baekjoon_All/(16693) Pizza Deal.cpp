#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define PI 3.141592
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	double A1, P1;
	double R1, P2;
	double ans1, ans2;
	cin >> A1 >> P1;
	cin >> R1 >> P2;
	ans1 = A1 / P1;
	ans2 = R1 * R1 * PI / P2;
	if (ans1 < ans2)
		cout << "Whole pizza";
	else if (ans1 > ans2)
		cout << "Slice of pizza";

	return 0;
}