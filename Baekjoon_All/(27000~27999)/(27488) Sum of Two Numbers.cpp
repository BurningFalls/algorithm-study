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
	int T;
	cin >> T;
	while (T--) {
		string N;
		cin >> N;
		string a = "", b = "";
		int asum = 0, bsum = 0;
		FOR(i, 0, LEN(N) - 1) {
			int tmp = N[i] - '0';
			if (tmp % 2 == 0) {
				tmp = tmp / 2;
				a += tmp + '0';
				b += tmp + '0';
				asum += tmp;
				bsum += tmp;
			}
			else if (tmp % 2 == 1) {
				tmp = tmp / 2;
				if (asum <= bsum) {
					a += tmp + 1 + '0';
					b += tmp + '0';
					asum += tmp + 1;
					bsum += tmp;
				}
				else if (asum > bsum) {
					a += tmp + '0';
					b += tmp + 1 + '0';
					asum += tmp;
					bsum += tmp + 1;
				}
			}
		}
		int A = stoi(a);
		int B = stoi(b);
		cout << A << " " << B << "\n";
	}

	return 0;
}