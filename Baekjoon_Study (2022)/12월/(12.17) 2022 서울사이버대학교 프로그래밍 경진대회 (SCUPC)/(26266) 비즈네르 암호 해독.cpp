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
	string A, B;
	cin >> A >> B;
	vector<int> diff(LEN(A));
	FOR(i, 0, LEN(A) - 1) {
		int a = A[i] - 'A';
		int b = B[i] - 'A';
		diff[i] = ((b + 25) - a) % 26;
	}
	int cut = LEN(A);
	FOR(i, 1, LEN(A) / 2) {
		if (LEN(A) % i != 0) continue;
		string s = "";
		string tmp = "";
		bool flag = true;
		FOR(j, 0, LEN(A) - 1) {
			tmp += diff[j] + 'A';
			if ((j + 1) % i == 0) {
				if (s.empty()) {
					s = tmp;
				}
				else {
					if (s != tmp) {
						flag = false;
						break;
					}
				}
				tmp = "";
			}
		}
		if (flag) {
			cut = i;
			break;
		}
	}

	FOR(i, 0, cut - 1) {
		char x = diff[i] + 'A';
		cout << x;
	}

	return 0;
}