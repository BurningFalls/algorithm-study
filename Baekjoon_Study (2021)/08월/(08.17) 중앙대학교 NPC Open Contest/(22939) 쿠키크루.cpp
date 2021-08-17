#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define INF 987654321

typedef struct _NODE {
	int x;
	int y;
} NODE;

int N;
char Map[101][101];
vector<NODE> J, C, B, W;
NODE H, E;

int Do(vector<NODE> v) {
	NODE arr[5];
	int dist[5][5] = { 0, };
	arr[0] = H;
	arr[1] = v[0];
	arr[2] = v[1];
	arr[3] = v[2];
	arr[4] = E;
	FOR(i, 0, 4) {
		FOR(j, i + 1, 4) {
			int d = abs(arr[i].x - arr[j].x) + abs(arr[i].y - arr[j].y);
			dist[i][j] = d;
			dist[j][i] = d;
		}
	}
	int num[3] = { 1, 2, 3 };
	bool flag = true;
	int mini = INF;
	while (flag) {
		int d = 0;
		d += dist[0][num[0]];
		d += dist[num[0]][num[1]];
		d += dist[num[1]][num[2]];
		d += dist[num[2]][4];
		mini = min(mini, d);
		flag = next_permutation(num, num + 3);
	}
	return mini;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			cin >> Map[i][j];
			if (Map[i][j] == 'J')
				J.push_back({ i, j });
			else if (Map[i][j] == 'C')
				C.push_back({ i, j });
			else if (Map[i][j] == 'B')
				B.push_back({ i, j });
			else if (Map[i][j] == 'W')
				W.push_back({ i, j });
			else if (Map[i][j] == 'H')
				H = { i, j };
			else if (Map[i][j] == '#')
				E = { i, j };
		}
	}
	int idx = -1;
	int mini = INF;
	int j, c, b, w;
	int arr[4];
	arr[0] = Do(J);
	arr[1] = Do(C);
	arr[2] = Do(B);
	arr[3] = Do(W);
	FOR(i, 0, 3) {
		if (mini > arr[i]) {
			mini = arr[i];
			idx = i;
		}
	}
	if (idx == 0)
		cout << "Assassin";
	else if (idx == 1)
		cout << "Healer";
	else if (idx == 2)
		cout << "Mage";
	else if (idx == 3)
		cout << "Tanker";


	return 0;
}