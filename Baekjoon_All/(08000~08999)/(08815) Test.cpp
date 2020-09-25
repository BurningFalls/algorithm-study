#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char arr[12] = { 'C', 'B', 'C', 'D', 'C', 'D', 'A', 'D', 'A', 'B', 'A', 'B' };
// AB/CBC/DCD/ADA/BAB/CBC/DCD
int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		if (N == 1)
			cout << "A";
		else if (N == 2)
			cout << "B";
		else {
			int temp = (N - 3) % 12;
			cout << arr[temp];
		}
		cout << "\n";
	}

	return 0;
}