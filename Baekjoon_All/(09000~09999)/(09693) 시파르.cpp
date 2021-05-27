#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int num = 5;
	vector<int> v;
	while (num <= 1000000) {
		v.push_back(num);
		num *= 5;
	}
	int vlen = v.size();
	int idx = 1;
	while (true) {
		int N;
		cin >> N;
		if (N == 0)
			break;
		int sum = 0;
		FOR(i, 0, vlen - 1) {
			sum += N / v[i];
		}
		cout << "Case #" << idx << ": " << sum << "\n";
		idx++;
	}


	return 0;
}