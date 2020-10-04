#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
string pn = "";
char num[7] = { '1', '2', '3', '5', '7', '9' };

bool is_Prime(int num) {
	if (num == 2)
		return true;
	FOR(i, 2, sqrt(num)) {
		if (num % i == 0)
			return false;
	}
	return true;
}

void DFS(int cnt) {
	if (cnt == N) {
		cout << pn << "\n";
		return;
	}
	FOR(i, 0, 5) {
		if (cnt == 0 && i == 0) continue;
		if (cnt != 0 && i == 1) continue;
		pn += num[i];
		if (is_Prime(stoi(pn)))
			DFS(cnt + 1);
		pn.pop_back();
	}
}

int main() {
	FASTIO;
	cin >> N;
	DFS(0);

	return 0;
}