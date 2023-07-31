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

int Calc(int x) {
    int cnt = 0;
    FOR(i, 0, 9) {
        if (x & (1 << i)) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    FASTIO;
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> dp(N);
    FOR(i, 0, N - 1) {
        cin >> A[i];
    }
    
    dp[0] = -INF;
    dp[1] = Calc(A[0] ^ A[1]);
    dp[2] = Calc((A[0] ^ A[1]) ^ A[2]);
    FOR(i, 3, N - 1) {
        int t1 = dp[i - 3] + Calc((A[i - 2] ^ A[i - 1]) ^ A[i]);
        int t2 = dp[i - 2] + Calc(A[i - 1] ^ A[i]);
        if (t1 < 0) t1 = -INF;
        if (t2 < 0) t2 = -INF;
        dp[i] = max(t1, t2);
    }
    cout << (dp[N - 1] < 0 ? 0 : dp[N - 1]) << "\n";
    
    return 0;
}
