#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

pii arr[6] = { {1, 3}, {3, 1}, {1, 4}, {4, 1}, {3, 4}, {4, 3} };

int main() {
	FASTIO;
	int N;
	cin >> N;
	int cnt1 = 0;
	int cnt2 = 0;
	FOR(i, 1, N) {
		int a, b;
		cin >> a >> b;
		pii tmp = { a, b };
		bool flag = false;
		FOR(j, 0, 5) {
			if (tmp == arr[j]) {
				flag = true;
				break;
			}
		}
		if (flag)
			cnt1++;
		else
			cnt2++;
	}
	if (cnt1 == 3 && cnt2 == 0)
		cout << "Wa-pa-pa-pa-pa-pa-pow!";
	else
		cout << "Woof-meow-tweet-squeek";

	return 0;
}