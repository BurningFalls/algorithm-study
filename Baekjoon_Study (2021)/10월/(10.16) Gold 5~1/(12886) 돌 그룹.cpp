#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

bool visited[1501][1501] = { 0, };

bool BFS(int A, int B, int C) {
	int sum = A + B + C;
	queue<pii> q;
	visited[A][B] = 1;
	q.push({ A, B });
	while (!q.empty()) {
		int arr[3];
		arr[0] = q.front().first;
		arr[1] = q.front().second;
		arr[2] = sum - arr[0] - arr[1];
		q.pop();
		if (arr[0] == arr[1] && arr[1] == arr[2]) {
			return 1;
		}
		FOR(i, 0, 2) {
			FOR(j, i + 1, 2) {
				if (arr[i] == arr[j]) continue;
				int narr[3] = { arr[0], arr[1], arr[2] };
				if (arr[i] > arr[j]) {
					narr[i] -= arr[j];
					narr[j] += arr[j];
				}
				else if (arr[i] < arr[j]) {
					narr[i] += arr[i];
					narr[j] -= arr[i];
				}
				if (visited[narr[0]][narr[1]]) continue;
				visited[narr[0]][narr[1]] = 1;
				q.push({ narr[0], narr[1] });
			}
		}
	}
	return 0;
}

int main() {
	FASTIO;
	int A, B, C;
	cin >> A >> B >> C;
	cout << BFS(A, B, C);

	return 0;
}