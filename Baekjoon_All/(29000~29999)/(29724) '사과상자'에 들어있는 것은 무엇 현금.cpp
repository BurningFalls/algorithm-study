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
    ll sum = 0;
    ll apple = 0;
    FOR(i, 1, N) {
        char T;
        ll W, H, L;
        cin >> T >> W >> H >> L;
        ll w = 0;
        if (T == 'A') {
            w = (W / 12) * (H / 12) * (L / 12);
            apple += w;
            w = w * 500 + 1000;
        }
        else if (T == 'B') {
            w = 6000;
        }
        sum += w;
    }
    cout << sum << "\n" << 4000 * apple << "\n";
    
    return 0;
}


