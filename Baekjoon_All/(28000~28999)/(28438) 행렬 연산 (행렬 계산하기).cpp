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
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> Map(N + 1, vector<int>(M + 1, 0));
    vector<int> addR(N + 1, 0), addC(M + 1, 0);
    FOR(q, 1, Q) {
        int kind;
        cin >> kind;
        if (kind == 1) {
            int R, V;
            cin >> R >> V;
            addR[R] += V;
        }
        else if (kind == 2) {
            int C, V;
            cin >> C >> V;
            addC[C] += V;
        }
    }
    
    FOR(i, 1, N) {
        FOR(j, 1, M) {
            cout << Map[i][j] + addR[i] + addC[j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}


