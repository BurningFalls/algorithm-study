#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int main() {
	FASTIO;
	int N;
	cin >> N;
	priority_queue<int> pq1, pq2;
	ll xsum = 0;
	ll ysum1 = 0, ysum2 = 0;
	FOR(i, 1, N) {
		int x, y;
		cin >> x >> y;
		xsum += abs(x);
		if (i % 2 == 1) {
			pq1.push(y);
			ysum1 += y;
		}
		else if (i % 2 == 0) {
			pq2.push(-y);
			ysum2 += y;
		}
		if (i != 1) {
			int a = pq1.top();
			int b = -pq2.top();
			if (a > b) {
				pq1.pop();
				pq2.pop();
				pq1.push(b);
				pq2.push(-a);
				ysum1 = ysum1 - a + b;
				ysum2 = ysum2 - b + a;
			}
		}
		ll mid = pq1.top();
		cout << mid << " ";
		cout << xsum + (ysum2 - mid * (i / 2)) + (mid * (i - i / 2) - ysum1) << "\n";
	}


	return 0;
}