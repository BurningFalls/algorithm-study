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
    ll N, M;
    cin >> N >> M;
    ll T, S;
    cin >> T >> S;
    
    ll t1 = N + ((N - 1) / 8) * S;
    ll t2 = T + M + ((M - 1) / 8) * (S + 2 * T);
    
    if (t1 < t2) {
        cout << "Zip\n" << t1 << "\n";
    }
    else if (t1 > t2) {
        cout << "Dok\n" << t2 << "\n";
    }
    
    
    return 0;
}


