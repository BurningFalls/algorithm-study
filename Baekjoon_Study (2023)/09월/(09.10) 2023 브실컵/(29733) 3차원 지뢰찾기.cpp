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

int main() {
    FASTIO;
    int R, C, H;
    cin >> R >> C >> H;
    vector<vector<vector<char>>> Map(H + 1, vector<vector<char>>(R + 1, vector<char>(C + 1)));
    FOR(i, 1, H) {
        FOR(j, 1, R) {
            FOR(k, 1, C) {
                cin >> Map[i][j][k];
            }
        }
    }
    
    vector<int> dz = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1,
        0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1
    };
    vector<int> dy = {
        -1, -1, -1, 0, 0, 0, 1, 1, 1,
        -1, -1, -1, 0, 0, 1, 1, 1,
        -1, -1, -1, 0, 0, 0, 1, 1, 1
    };
    vector<int> dx = {
        -1, 0, 1, -1, 0, 1, -1, 0, 1,
        -1, 0, 1, -1, 1, -1, 0, 1,
        -1, 0, 1, -1, 0, 1, -1, 0, 1
    };
    
    FOR(i, 1, H) {
        FOR(j, 1, R) {
            FOR(k, 1, C) {
                if (Map[i][j][k] == '*') continue;
                int cnt = 0;
                FOR(t, 0, 25) {
                    int nz = i + dz[t];
                    int ny = j + dy[t];
                    int nx = k + dx[t];
                    if (nz < 1 || ny < 1 || nx < 1) continue;
                    if (nz > H || ny > R || nx > C) continue;
                    cnt += (Map[nz][ny][nx] == '*');
                }
                Map[i][j][k] = (cnt % 10) + '0';
            }
        }
    }
    
    FOR(i, 1, H) {
        FOR(j, 1, R) {
            FOR(k, 1, C) {
                cout << Map[i][j][k];
            }
            cout << "\n";
        }
    }
    
    
    return 0;
}

