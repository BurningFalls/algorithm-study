#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int main() {
	FASTIO;
	int N;
	int num;
	while (true) {
		int zero_cnt = 0;
		int one_cnt = 0;
		cin >> N;
		if (N == 0)
			break;
		FOR(i, 1, N) {
			cin >> num;
			if (num == 0)
				zero_cnt++;
			else if (num == 1)
				one_cnt++;
		}
		cout << "Mary won ";
		cout << zero_cnt;
		cout << " times and John won ";
		cout << one_cnt;
		cout << " times\n";
	}


	return 0;
}