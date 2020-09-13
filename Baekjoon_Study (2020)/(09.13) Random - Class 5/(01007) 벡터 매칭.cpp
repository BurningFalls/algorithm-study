#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)

int N;
vector<pair<double, double>> pos_v;
bool visited[21] = { 0, };
double ans;

void DFS(int cnt, int one_cnt) {
	if (one_cnt == N / 2) {
		double a = 0, b = 0;
		FOR(i, 0, N - 1) {
			if (visited[i]) {
				a += pos_v[i].first;
				b += pos_v[i].second;
			}
			else if (!visited[i]) {
				a -= pos_v[i].first;
				b -= pos_v[i].second;
			}
		}
		if (ans == -1)
			ans = sqrt(a * a + b * b);
		else
			ans = min(ans, sqrt(a * a + b * b));
		return;
	}
	if (cnt == N)
		return;
	visited[cnt] = 1;
	DFS(cnt + 1, one_cnt + 1);
	visited[cnt] = 0;
	DFS(cnt + 1, one_cnt);
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	cout << fixed << setprecision(6);
	while (T--) {
		ans = -1;
		cin >> N;
		FOR(i, 0, N - 1)
			visited[i] = 0;
		pos_v.clear();
		FOR(i, 1, N) {
			double x, y;
			cin >> x >> y;
			pos_v.push_back({ x, y });
		}
		DFS(0, 0);
		cout << ans << "\n";
	}

	return 0;
}