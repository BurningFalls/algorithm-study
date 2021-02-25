#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int
#define MAX 200000 + 1

struct ball {
	int weight;
	int color;
	int idx;
};

int ans[MAX] = { 0, };
int C[MAX] = { 0, };
int S[MAX] = { 0, };
int N;

bool compare(ball& a, ball& b) {
	if (a.weight == b.weight)
		return a.color < b.color;
	return a.weight < b.weight;
}

int main() {
	FASTIO;
	vector<ball> v;
	cin >> N;
	FOR(i, 0, N - 1) {
		int weight, color;
		cin >> color >> weight;
		v.push_back({ weight, color, i });
	}
	sort(v.begin(), v.end(), compare);
	int sum = 0;
	FOR(i, 0, N - 1) {
		int weight = v[i].weight;
		int color = v[i].color;
		int idx = v[i].idx;
		C[color] += weight;
		S[weight] += weight;
		sum += weight;
		ans[idx] = sum - C[color] - S[weight] + weight;
		if (i != 0 && (v[i - 1].color == color) && (v[i - 1].weight == weight))
			ans[idx] = ans[v[i - 1].idx];
	}

	FOR(i, 0, N - 1)
		cout << ans[i] << "\n";


	return 0;
}