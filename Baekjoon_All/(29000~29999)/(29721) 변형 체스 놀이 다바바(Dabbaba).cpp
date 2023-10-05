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

struct NODE {
    int x;
    int y;
    
    bool operator< (const NODE &n) const {
        if (x == n.x)
            return y < n.y;
        return x < n.x;
    }
};

int main() {
    FASTIO;
    int N, K;
    cin >> N >> K;
    set<NODE> se1, se2;
    FOR(i, 0, K - 1) {
        int x, y;
        cin >> x >> y;
        se1.insert({x, y});
    }
    
    vector<int> dy = {-2, 2, 0, 0};
    vector<int> dx = {0, 0, -2, 2};
    for(auto &n : se1) {
        FOR(i, 0, 3) {
            int nx = n.x + dx[i];
            int ny = n.y + dy[i];
            if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if (se1.count({nx, ny})) continue;
            se2.insert({nx, ny});
        }
    }
    
    int len = LEN(se2);
    cout << len << "\n";
    
    
    return 0;
}

