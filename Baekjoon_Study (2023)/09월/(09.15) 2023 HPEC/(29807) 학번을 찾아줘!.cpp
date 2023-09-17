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
    int T;
    cin >> T;
    vector<int> v(T);
    FOR(i, 0, T - 1) {
        cin >> v[i];
    }
    
    ll ans = 0;
    if (v[0] > v[2]) {
        ans += (v[0] - v[2]) * 508;
    }
    else {
        ans += (v[2] - v[0]) * 108;
    }
    if (v[1] > v[3]) {
        ans += (v[1] - v[3]) * 212;
    }
    else {
        ans += (v[3] - v[1]) * 305;
    }
    if (v[4] != 0) {
        v[4] *= 707;
    }
    ans += v[4];
    ans *= 4763;
    cout << ans << "\n";
    
    return 0;
}



