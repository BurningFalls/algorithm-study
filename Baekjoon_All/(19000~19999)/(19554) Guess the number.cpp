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
	int N;
	cin >> N;
	int left = 1, right = N;
	while (true) {
		int mid = (left + right) / 2;
		cout << "? " << mid << endl;
		int input;
		cin >> input;
		if (input == -1) {
			left = mid + 1;
		}
		else if (input == 0) {
			cout << "= " << mid << endl;
			break;
		}
		else if (input == 1) {
			right = mid - 1;
		}
	}

	return 0;
}