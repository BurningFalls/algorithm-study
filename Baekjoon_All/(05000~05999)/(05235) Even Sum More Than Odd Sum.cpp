#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int even_sum = 0;
		int odd_sum = 0;
		FOR(i, 1, N) {
			int num;
			cin >> num;
			if (num % 2 == 0)
				even_sum += num;
			else if (num % 2 == 1)
				odd_sum += num;
		}
		if (even_sum == odd_sum)
			cout << "TIE";
		else if (even_sum > odd_sum)
			cout << "EVEN";
		else if (even_sum < odd_sum)
			cout << "ODD";
		cout << "\n";
	}


	return 0;
}