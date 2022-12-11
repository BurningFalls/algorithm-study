#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int K;
int max_num;
vector<int> v;
vector<int> maxi;
ll ans = 0;

int DFS(int node) {
	int& ret = maxi[node];
	int left = node * 2 + 1;
	int right = node * 2 + 2;
	if (left > max_num) return ret = 0;
	return ret = max(DFS(left) + v[left], DFS(right) + v[right]);
}

void DFS2(int node, int sum) {
	int left = node * 2 + 1;
	int right = node * 2 + 2;
	int tmp1 = max(sum - maxi[left], v[left]);
	int tmp2 = max(sum - maxi[right], v[right]);
	ans += tmp1 + tmp2;
	if (left > (1 << K) - 2) return;
	DFS2(left, sum - tmp1);
	DFS2(right, sum - tmp2);
}

int main() {
	FASTIO;
	cin >> K;
	max_num = (1 << (K + 1)) - 2;
	v = vector<int>(max_num + 1);
	maxi = vector<int>(max_num + 1);
	FOR(i, 1, max_num) {
		cin >> v[i];
	}

	DFS(0);
	DFS2(0, maxi[0]);
	cout << ans;

	return 0;
}