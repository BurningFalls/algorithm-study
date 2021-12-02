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

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int x1, p1, x2, p2;
		cin >> x1 >> p1;
		cin >> x2 >> p2;
		int lenA = LEN(to_string(x1)) + p1;
		int lenB = LEN(to_string(x2)) + p2;
		if (lenA > lenB) {
			cout << '>';
		}
		else if (lenA < lenB) {
			cout << '<';
		}
		else if (lenA == lenB) {
			string s1 = to_string(x1);
			string s2 = to_string(x2);
			bool flag = false;
			FOR(i, 0, min(LEN(s1), LEN(s2)) - 1) {
				if (s1[i] > s2[i]) {
					cout << '>';
					flag = true;
					break;
				}
				else if (s1[i] < s2[i]) {
					cout << '<';
					flag = true;
					break;
				}
			}
			if (!flag) {
				if (LEN(s1) > LEN(s2)) {
					FOR(i, LEN(s2), LEN(s1) - 1) {
						if (s1[i] > '0') {
							cout << '>';
							flag = true;
							break;
						}
						else if (s1[i] < '0') {
							cout << '<';
							flag = true;
							break;
						}
					}
				}
				else if (LEN(s1) == LEN(s2)) {
					cout << '=';
					flag = true;
				}
				else if (LEN(s1) < LEN(s2)) {
					FOR(i, LEN(s1), LEN(s2) - 1) {
						if (s2[i] > '0') {
							cout << '<';
							flag = true;
							break;
						}
						else if (s2[i] < '0') {
							cout << '>';
							flag = true;
							break;
						}
					}
				}
			}
			if (!flag) {
				cout << '=';
			}
		}
		cout << "\n";
	}


	return 0;
}