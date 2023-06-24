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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> T(N, vector<int>(M));
    vector<vector<int>> dp(N, vector<int>(M));
    FOR(i, 0, N - 1) {
        FOR(j, 0, M - 1) {
            cin >> T[i][j];
        }
    }
    FOR(j, 0, M - 1) {
        dp[0][j] = T[0][j];
    }

    FOR(i, 1, N - 1) {
        FOR(j, 0, M - 1) {
            int mini = INF;
            FOR(k, 0, M - 1) {
                if (k == j) continue;
                mini = min(mini, dp[i - 1][k]);
            }
            dp[i][j] = mini + T[i][j];
        }
    }

    int ans = INF;
    FOR(j, 0, M - 1) {
        ans = min(ans, dp[N - 1][j]);
    }
    cout << ans;

    return 0;
}
