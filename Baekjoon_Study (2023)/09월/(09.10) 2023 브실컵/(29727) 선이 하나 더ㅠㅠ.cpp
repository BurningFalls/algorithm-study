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
    ll N;
    cin >> N;
    ll xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    ll t = (N + 1) * N / 2;
    ll sum = t * t;
    if (ya == yb) {
        if (xa > xb) {
            swap(xa, xb);
        }
        ll left = max(-1LL, xa);
        ll right = min(N, xb);
        ll tt = max(0LL, right - left);
        tt = tt * (tt - 1) / 2;
        
        sum += (N + 1) * tt;
    }
    else if (xa == xb) {
        if (ya > yb) {
            swap(ya, yb);
        }
        ll left = max(-1LL, ya);
        ll right = min(N, yb);
        ll tt = max(0LL, right - left);
        tt = tt * (tt - 1) / 2;
        
        sum += (N + 1) * tt;
    }
    cout << sum << "\n";
    
    return 0;
}

