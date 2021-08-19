#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	double N;
	int M;
	cin >> N >> M;
	double sum = 0;
	FOR(i, 1, M) {
		double a, b;
		cin >> a >> b;
		sum += a * b;
	}
	cout << fixed << setprecision(6);
	cout << N * sum;


	return 0;
}