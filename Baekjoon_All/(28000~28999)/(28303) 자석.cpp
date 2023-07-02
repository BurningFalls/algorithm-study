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
    int N; ll K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> Lcalc(N), Rcalc(N);
    vector<ll> Lmini(N), Rmini(N);
    FOR(i, 0, N - 1) {
        cin >> A[i];
    }
    FOR(i, 0, N - 1) {
        Lcalc[i] = A[i] - (i + 1) * K;
        Lmini[i] = (i == 0 ? Lcalc[i] : min(Lmini[i - 1], Lcalc[i]));
    }
    ROF(i, N - 1, 0) {
        Rcalc[i] = A[i] - (N - i) * K;
        Rmini[i] = (i == N - 1 ? Rcalc[i] : min(Rmini[i + 1], Rcalc[i]));
    }
    
    ll ans = -LINF;
    FOR(i, 1, N - 1) {
        ans = max(ans, Lcalc[i] - Lmini[i - 1]);
    }
    ROF(i, N - 2, 0) {
        ans = max(ans, Rcalc[i] - Rmini[i + 1]);
    }
    cout << ans;
    
    return 0;
}





