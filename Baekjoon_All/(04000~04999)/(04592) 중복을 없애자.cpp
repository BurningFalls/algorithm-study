#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	while (true) {
		int N;
		cin >> N;
		if (N == 0)
			break;
		vector<int> v;
		FOR(i, 1, N) {
			int num;
			cin >> num;
			if (v.empty())
				v.push_back(num);
			else {
				if (v.back() == num) continue;
				v.push_back(num);
			}
		}
		for (int n : v)
			cout << n << " ";
		cout << "$\n";
	}

	return 0;
}