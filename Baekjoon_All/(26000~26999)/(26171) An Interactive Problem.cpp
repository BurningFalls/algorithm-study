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
	int col = 1, row = 1;
	int mrow = 0;
	int maxi = 0;
	while (true) {
		string input;
		cout << "? " << col << " " << row << endl;
		cin >> input;
		if (input == "ArrayIndexOutOfBoundsException") {
			if (mrow != 0) {
				break;
			}
			mrow = row - 1;
			col++;
			row = 1;
		}
		else {
			maxi = max(maxi, stoi(input));
			if (row == mrow) {
				col++;
				row = 1;
			}
			else {
				row++;
			}
		}
	}

	cout << "! " << maxi;

	return 0;
}