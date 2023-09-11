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
    FOR(t, 1, T) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": ";
        
        if (N > 4500) {
            cout << "Round 1";
        }
        else if (N > 1000) {
            cout << "Round 2";
        }
        else if (N > 25) {
            cout << "Round 3";
        }
        else {
            cout << "World Finals";
        }
        cout << "\n";
    }
    
    
    return 0;
}


