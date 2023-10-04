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
#define MOD 1000000007

int main() {
    FASTIO;
    ll N, M;
    cin >> N >> M;
    ll t1 = 1, t2 = 1;
    FOR(i, 1, N) {
        t1 = (t1 * M) % MOD;
    }
    FOR(i, 1, N) {
        t2 = (t2 * (M - 1)) % MOD;
    }
    
    ll ans = (t1 - t2 + MOD) % MOD;
    cout << ans << "\n";
    
    return 0;
}

