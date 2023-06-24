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
#define MAX 22

struct NODE {
    pii c1;
    pii c2;
};

int N, M;
vector<vector<char>> Map(MAX, vector<char>(MAX));
int visited[MAX][MAX][MAX][MAX];
pii sc1, sc2;

int BFS() {
    queue<NODE> q;
    vector<int> dy = {-1, 1, 0, 0};
    vector<int> dx = {0, 0, -1, 1};
    q.push({sc1, sc2});
    visited[sc1.first][sc1.second][sc2.first][sc2.second] = 1;
    while(!q.empty()) {
        pii c1 = q.front().c1;
        pii c2 = q.front().c2;
        q.pop();
        bool f1 = false, f2 = false;
        if (c1.first < 1 || c1.first > N || c1.second < 1 || c1.second > M) f1 = true;
        if (c2.first < 1 || c2.first > N || c2.second < 1 || c2.second > M) f2 = true;
        if (f1 && f2) continue;
        if ((f1 ^ f2)) return visited[c1.first][c1.second][c2.first][c2.second];
        FOR(i, 0, 3) {
            pii nc1 = {c1.first + dy[i], c1.second + dx[i]};
            pii nc2 = {c2.first + dy[i], c2.second + dx[i]};
            if (Map[nc1.first][nc1.second] == '#') {
                nc1 = c1;
            }
            if (Map[nc2.first][nc2.second] == '#') {
                nc2 = c2;
            }
            if (visited[nc1.first][nc1.second][nc2.first][nc2.second]) continue;
            visited[nc1.first][nc1.second][nc2.first][nc2.second] = visited[c1.first][c1.second][c2.first][c2.second] + 1;
            q.push({nc1, nc2});
        }
    }
    return 0;
}

int main() {
    memset(visited, 0, sizeof(visited));
    bool flag = false;
    cin >> N >> M;
    FOR(i, 1, N) {
        FOR(j, 1, M) {
            cin >> Map[i][j];
            if (Map[i][j] == 'o') {
                if (!flag) {
                    sc1 = {i, j};
                    flag = true;
                    Map[i][j] = '.';
                }
                else if (flag) {
                    sc2 = {i, j};
                    Map[i][j] = '.';
                }
            }
        }
    }
    
    cout << BFS() - 1;
    
    return 0;
}

