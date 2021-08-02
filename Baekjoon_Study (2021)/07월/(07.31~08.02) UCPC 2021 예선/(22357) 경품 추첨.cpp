#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int K, N;
vector<int> prime_v;

bool is_Prime(int x) {
	int tmp = sqrt(x);
	FOR(i, 2, tmp) {
		if (x % i == 0)
			return false;
	}
	return true;
}

void Find_Prime() {
	int num = N + 1;
	int cnt = 0;
	while (cnt < K) {
		if (is_Prime(num)) {
			cnt++;
			prime_v.push_back(num);
		}
		num++;
	}
}

int main() {
	FASTIO;
	cin >> K >> N;
	Find_Prime();
	for (int d : prime_v) {
		for (int num = d; num <= d * N; num += d)
			cout << num << " ";
		cout << "\n";
	}


	return 0;
}