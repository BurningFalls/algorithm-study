#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define MEMSET(arr, num) memset(arr, num, sizeof(arr));
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define LEN(s) int(s.size())

int N, M;
int arr[31];
bool dp[32][15001] = { 0, };

void DP(int node, int weight) {
	if (node > N + 1)
		return;
	if (dp[node][weight])
		return;
	dp[node][weight] = 1;
	DP(node + 1, weight + arr[node]);
	DP(node + 1, abs(weight - arr[node]));
	DP(node + 1, weight);
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	DP(1, 0);
	int weight;
	vector<char> ans;
	cin >> M;
	FOR(i, 1, M) {
		cin >> weight;
		if (weight > 15000)
			ans.push_back('N');
		else
			ans.push_back(dp[N + 1][weight] ? 'Y' : 'N');
	}
	for (char x : ans)
		cout << x << " ";


	return 0;
}