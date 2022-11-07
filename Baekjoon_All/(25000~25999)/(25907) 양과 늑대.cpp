#include <bits/stdc++.h>
using namespace std;

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
	int N;
	cin >> N;
	int L = 1, R = 2;
	int left = 2, right = N - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		cout << "? " << mid << endl;
		int sheep, wolf;
		cin >> sheep;
		wolf = mid - sheep;
		if (sheep == wolf) {
			cout << "! " << mid << endl;
			break;
		}
		if (sheep > wolf) {
			if (L == 1 && R == 2) {
				left = mid + 1;
			}
			else if (L == 2 && R == 1) {
				right = mid - 1;
			}
		}
		else if (sheep < wolf) {
			if (L == 1 && R == 2) {
				right = mid - 1;
			}
			else if (L == 2 && R == 1) {
				left = mid + 1;
			}
		}
	}

	return 0;
}