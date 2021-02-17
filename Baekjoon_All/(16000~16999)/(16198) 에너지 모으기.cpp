#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int N;
bool use[11] = { 0, };
int W[11];
int maximum = 0;
int energy = 0;

void DFS(int cnt) {
	if (cnt == 2) {
		maximum = max(maximum, energy);
		return;
	}
	FOR(i, 2, N - 1) {
		if (use[i]) continue;
		int left = i - 1, right = i + 1;
		while (use[left])
			left--;
		while (use[right])
			right++;
		energy += W[left] * W[right];
		use[i] = 1;
		DFS(cnt - 1);
		energy -= W[left] * W[right];
		use[i] = 0;
	}
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N)
		cin >> W[i];
	DFS(N);
	cout << maximum;

	return 0;
}