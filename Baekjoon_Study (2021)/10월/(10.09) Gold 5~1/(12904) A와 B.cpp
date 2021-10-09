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
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

int main() {
	FASTIO;
	string S, T;
	cin >> S >> T;
	int left = 0, right = LEN(T) - 1;
	bool Back = true;
	while (LEN(S) != right - left + 1) {
		if (Back) {
			if (T[right] == 'B') {
				Back = !Back;
			}
			right--;
		}
		else if (!Back) {
			if (T[left] == 'B') {
				Back = !Back;
			}
			left++;
		}
	}
	bool flag = true;
	if (Back) {
		FOR(i, 0, LEN(S) - 1) {
			if (S[i] != T[left + i]) {
				flag = false;
				break;
			}
		}
	}
	else if (!Back) {
		FOR(i, 0, LEN(S) - 1) {
			if (S[i] != T[right - i]) {
				flag = false;
				break;
			}
		}
	}
	
	P1(flag);


	return 0;
}