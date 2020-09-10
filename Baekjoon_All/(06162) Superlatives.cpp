#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int K;
	cin >> K;
	int cnt = 1;
	while (K--) {
		ll E, A;
		cin >> E >> A;
		cout << "Data Set " << cnt << ":\n";
		if (E <= A)
			cout << "no drought";
		else {
			ll idx = 1;
			int x = 1;
			while (true) {
				if ((E > idx* A) && (E <= idx * 5 * A)) {
					FOR(i, 1, x - 1)
						cout << "mega ";
					cout << "drought";
					break;
				}
				idx *= 5;
				x++;
			}
		}
		cout << "\n\n";
		cnt++;
	}

	return 0;
}