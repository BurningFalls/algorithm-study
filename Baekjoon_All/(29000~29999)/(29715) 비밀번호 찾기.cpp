#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define ROF(i,a,b) for(ll i=(a);i>=(b);i--)
#define ll long long int
#define pii pair<int, int>
#define PQ priority_queue
#define LEN(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define INF (int)2e9
#define LINF (ll)1e18

int main() {
    FASTIO;
    ll N, M;
    ll X, Y;
    cin >> N >> M;
    cin >> X >> Y;
    
    ll A = 0, B = 0;
    FOR(i, 1, M) {
        int a, b;
        cin >> a >> b;
        if (a != 0) {
            A++;
        }
        else if (a == 0) {
            B++;
        }
    }
    
    ll left = 9 - A - B;
    ll right = N - A - B;
    ll result = 1;
    ROF(i, left, left - right + 1) {
        result *= i;
    }
    FOR(i, 1, right) {
        result /= i;
    }
    FOR(i, 1, N - A) {
        result *= i;
    }
    
    ll ans = result * X + ((result - 1) / 3) * Y;
    cout << ans << "\n";
    
    
    return 0;
}

