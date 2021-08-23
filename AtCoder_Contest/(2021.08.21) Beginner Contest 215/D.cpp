#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N, M;
bool used[100001] = { 0, };
vector<int> ans_v;

int main() {
	FASTIO;
	cin >> N >> M;
	FOR(i, 1, N) {
		int num;
		cin >> num;
		int div = 2;
		while (div * div <= num) {
			if (num % div == 0) {
				used[div] = 1;
				num /= div;
			}
			else if (num % div != 0)
				div++;
		}
		if (num != 1)
			used[num] = 1;
	}
	ROF(i, M, 2) {
		if (!used[i]) continue;
		for (int j = i * 2; j <= M; j += i)
			used[j] = 1;
	}
	FOR(i, 1, M) {
		if (used[i]) continue;
		ans_v.push_back(i);
	}
	int len = ans_v.size();
	cout << len << "\n";
	for (int x : ans_v)
		cout << x << "\n";


	return 0;
}