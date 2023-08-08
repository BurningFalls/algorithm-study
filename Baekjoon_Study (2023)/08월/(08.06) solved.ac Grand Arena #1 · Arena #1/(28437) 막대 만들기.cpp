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
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> dp(100001, 0);
    FOR(i, 0, N - 1) {
        cin >> A[i];
        dp[A[i]]++;
    }
    
    FOR(i, 1, 50000) {
        for(int j = i + i; j <= 100000; j += i) {
            dp[j] += dp[i];
        }
    }
    
    int Q;
    cin >> Q;
    vector<int> L(Q);
    FOR(i, 0, Q - 1) {
        cin >> L[i];
        cout << dp[L[i]] << " ";
    }
    cout << "\n";
    
    return 0;
}


