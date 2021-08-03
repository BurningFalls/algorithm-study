#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

char color[300001];
deque<int> weight;

int main() {
	FASTIO;
	int N;
	cin >> N;
	FOR(i, 1, N)
		cin >> color[i];
	char prev = 'A';
	FOR(i, 1, N) {
		int w;
		cin >> w;
		if (color[i] != prev) {
			weight.push_back(w);
			prev = color[i];
		}
		else if (color[i] == prev) {
			weight.back() = max(weight.back(), w);
		}
	}
	int len = weight.size();
	int cnt = (len - 1) / 2;
	if (cnt == 0) {
		cout << 0;
		return 0;
	}
	weight.pop_front();
	weight.pop_back();
	sort(weight.begin(), weight.end(), greater<int>());
	ll sum = 0;
	FOR(i, 0, cnt - 1)
		sum += weight[i];
	cout << sum;

	return 0;
}