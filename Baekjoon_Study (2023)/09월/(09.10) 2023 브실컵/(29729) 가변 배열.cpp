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
    int S, N, M;
    cin >> S >> N >> M;
    
    int maxi = S;
    int cur = 0;
    
    FOR(i, 1, N + M) {
        int k;
        cin >> k;
        if (k == 1) {
            if (cur == maxi) {
                maxi *= 2;
            }
            cur++;
        }
        else if (k == 0) {
            cur--;
        }
    }
    cout << maxi << "\n";
    
    return 0;
}


