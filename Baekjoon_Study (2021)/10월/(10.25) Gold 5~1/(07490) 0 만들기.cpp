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

char Oper[3] = { ' ', '+', '-' };

int Calculate(int N, vector<char> & oper) {
	vector<int> v;
	string tmp = "1";
	FOR(i, 0, N - 2) {
		char x = i + 2 + '0';
		if (oper[i] == ' ') {
			tmp += x;
		}
		else {
			v.push_back(stoi(tmp));
			tmp = x;
		}
	}
	v.push_back(stoi(tmp));
	int ans = v[0];
	int idx = 1;
	FOR(i, 0, N - 2) {
		if (oper[i] == ' ') continue;
		if (oper[i] == '+') {
			ans += v[idx];
		}
		else if (oper[i] == '-') {
			ans -= v[idx];
		}
		idx++;
	}
	return ans;
}

void DFS(int node, int N, vector<char>& oper) {
	if (node == N - 1) {
		int res = Calculate(N, oper);
		if (res == 0) {
			FOR(i, 0, N - 2) {
				cout << i + 1;
				cout << oper[i];
			}
			cout << N << "\n";
		}
		return;
	}
	FOR(i, 0, 2) {
		oper[node] = Oper[i];
		DFS(node + 1, N, oper);
	}
}

int main() {
	FASTIO;
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<char> oper(N - 1);
		DFS(0, N, oper);
		cout << "\n";
	}


	return 0;
}