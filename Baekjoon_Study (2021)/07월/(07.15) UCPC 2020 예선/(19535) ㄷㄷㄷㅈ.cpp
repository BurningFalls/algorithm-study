#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

vector<pii> vertex;
int cnt[300001] = { 0, };

int main() {
	FASTIO;
	int N;
	int first = 0, second = 0;
	cin >> N;
	FOR(i, 1, N - 1) {
		int a, b;
		cin >> a >> b;
		vertex.push_back({ a, b });
		cnt[a]++; cnt[b]++;
	}
	FOR(i, 0, N - 2) {
		int n1 = vertex[i].first;
		int n2 = vertex[i].second;
		first += (cnt[n1] - 1) * (cnt[n2] - 1);
	}
	FOR(i, 1, N) {
		if (cnt[i] < 3) continue;
		second += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
	}
	if (first > second * 3)
		cout << "D";
	else if (first < second * 3)
		cout << "G";
	else if (first == second * 3)
		cout << "DUDUDUNGA";

	return 0;
}