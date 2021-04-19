#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

bool not_Prime[10001] = { 0, };

void Find_Prime() {
	not_Prime[1] = 1;
	FOR(i, 2, 10000) {
		if (not_Prime[i]) continue;
		for (int j = i * 2; j <= 10000; j += i) {
			not_Prime[j] = 1;
		}
	}
}

bool Func(int num) {
	set<int> s;
	while (true) {
		if (num == 1)
			return true;
		if (s.count(num))
			return false;
		s.insert(num);
		int sum = 0;
		while (num) {
			int tmp = num % 10;
			sum += tmp * tmp;
			num /= 10;
		}
		num = sum;
	}
}

int main() {
	FASTIO;
	Find_Prime();
	int P;
	cin >> P;
	bool flag;
	while (P--) {
		flag = true;
		int cnt, M;
		cin >> cnt >> M;
		if (not_Prime[M])
			flag = false;
		if (flag) {
			if (!Func(M))
				flag = false;
		}
		cout << cnt << " " << M << " ";
		cout << (flag ? "YES\n" : "NO\n");
	}


	return 0;
}