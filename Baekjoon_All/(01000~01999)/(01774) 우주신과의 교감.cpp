#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long int
#define ld long double
#define pii pair<ld, ld>
#define PQ priority_queue
#define LEN(v) int(v.size())
#define ALL(v) v.begin(),v.end()
#define INF 2e9
#define LINF 1e18
#define P1(a) cout << a << "\n"
#define P2(a, b) cout << a << " " << b << "\n";
#define P3(a, b, c) cout << a << " " << b << " " << c << "\n";

ld Calc_Dist(pii a, pii b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int Find_Parent(int node, vector<int>& Parent) {
	if (node == Parent[node])
		return node;
	return Parent[node] = Find_Parent(Parent[node], Parent);
}

bool is_Same(int n1, int n2, vector<int>& Parent) {
	n1 = Find_Parent(n1, Parent);
	n2 = Find_Parent(n2, Parent);
	return n1 == n2;
}

void Union(int n1, int n2, vector<int>& Parent) {
	n1 = Find_Parent(n1, Parent);
	n2 = Find_Parent(n2, Parent);
	Parent[n1] = n2;
}

ld DS(vector<int>& Parent, vector<pair<ld, pii>>& Edges) {
	ld ans = 0;
	FOR(i, 0, LEN(Edges) - 1) {
		ld dist = Edges[i].first;
		int a = Edges[i].second.first;
		int b = Edges[i].second.second;
		if (is_Same(a, b, Parent)) continue;
		Union(min(a, b), max(a, b), Parent);
		ans += dist;
	}
	return ans;
}

int main() {
	FASTIO;
	cout << fixed << setprecision(2);
	int N, M;
	cin >> N >> M;
	vector<pii> Pos(N);
	vector<vector<ld>> Dist(N, vector<ld>(N, 0));
	vector<int> Parent(N);
	vector<pair<ld, pii>> Edges;
	FOR(i, 0, N - 1) {
		cin >> Pos[i].first >> Pos[i].second;
		Parent[i] = i;
	}
	FOR(i, 0, N - 1) {
		FOR(j, i + 1, N - 1) {
			Dist[i][j] = Calc_Dist(Pos[i], Pos[j]);
		}
	}
	FOR(i, 0, M - 1) {
		int a, b;
		cin >> a >> b;
		a -= 1;
		b -= 1;
		Dist[min(a, b)][max(a, b)] = 0;
		Union(min(a, b), max(a, b), Parent);
	}
	FOR(i, 0, N - 1) {
		FOR(j, i + 1, N - 1) {
			if (Dist[i][j] == 0) continue;
			if (is_Same(i, j, Parent)) continue;
			Edges.push_back({ Dist[i][j], {i, j} });
		}
	}
	sort(ALL(Edges));
	cout << DS(Parent, Edges);


	return 0;
}