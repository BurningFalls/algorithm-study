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
    while(T--) {
        ll N;
        cin >> N;
        ll exp = N * (N + 1) / 2;
        ll left = 1, right = INF;
        ll ans = 0;
        while(left <= right) {
            ll mid = (left + right) / 2;
            if (exp < (mid - 1) * mid) {
                right = mid - 1;
            }
            else if (exp > mid * (mid + 1) - 1) {
                left = mid + 1;
            }
            else {
                ans = mid;
                break;
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}

