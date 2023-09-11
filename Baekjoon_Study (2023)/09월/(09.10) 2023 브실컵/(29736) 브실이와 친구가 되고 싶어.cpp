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
    int A, B;
    cin >> A >> B;
    int K, X;
    cin >> K >> X;
    int left = max(A, K - X);
    int right = min(B, K + X);
    int ans = right - left + 1;
    
    if (ans <= 0) {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << ans;
    }
    cout << "\n";
    
    
    return 0;
}


