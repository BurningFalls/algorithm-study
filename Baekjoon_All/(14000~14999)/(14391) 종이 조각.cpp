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

int Calc(int N, int M, vector<vector<char>>& Map, vector<vector<int>>& Sep) {
	int ans = 0;
	FOR(i, 0, N - 1) {
		int sum = 0;
		string s = "";
		FOR(j, 0, M - 1) {
			if (Sep[i][j] == 0) {
				s += Map[i][j];
			}
			else if (Sep[i][j] == 1) {
				if (!s.empty()) {
					sum += stoi(s);
					s = "";
				}
			}
		}
		if (!s.empty()) {
			sum += stoi(s);
		}
		ans += sum;
	}
	FOR(i, 0, M - 1) {
		int sum = 0;
		string s = "";
		FOR(j, 0, N - 1) {
			if (Sep[j][i] == 1) {
				s += Map[j][i];
			}
			else if (Sep[j][i] == 0) {
				if (!s.empty()) {
					sum += stoi(s);
					s = "";
				}
			}
		}
		if (!s.empty()) {
			sum += stoi(s);
		}
		ans += sum;
	}
	return ans;
}

int DFS(int node, int N, int M, vector<vector<char>>& Map, vector<vector<int>>& Sep) {
	if (node == N * M) {
		return Calc(N, M, Map, Sep);
	}
	int y = node / M;
	int x = node % M;
	int maxi = 0;
	FOR(i, 0, 1) {
		Sep[y][x] = i;
		maxi = max(maxi, DFS(node + 1, N, M, Map, Sep));
	}
	return maxi;
}

int main() {
	FASTIO;
	int N, M;
	cin >> N >> M;
	vector<vector<char>> Map(N, vector<char>(M));
	vector<vector<int>> Sep(N, vector<int>(M, -1));
	FOR(i, 0, N - 1) {
		FOR(j, 0, M - 1) {
			cin >> Map[i][j];
		}
	}
	cout << DFS(0, N, M, Map, Sep);

	return 0;
}