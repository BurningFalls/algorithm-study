#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
	FASTIO;
	int n;
	cin >> n;
	int p = 0;
	int num = 1;
	while (true) {
		if (n % num == 0 && (n / num) % 2 == 1) {
			break;
		}
		p++;
		num *= 2;
	}
	cout << n / num << " " << p;

	return 0;
}