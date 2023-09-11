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
    map<char, int> mp;
    mp['K'] = 0; mp['k'] = 0;
    mp['P'] = 1; mp['p'] = -1;
    mp['N'] = 3; mp['n'] = -3;
    mp['B'] = 3; mp['b'] = -3;
    mp['R'] = 5; mp['r'] = -5;
    mp['Q'] = 9; mp['q'] = -9;
    
    int sum = 0;
    FOR(i, 0, 7) {
        FOR(j, 0, 7) {
            char x;
            cin >> x;
            sum += mp[x];
        }
    }
    
    cout << sum << "\n";
    
    
    
    return 0;
}


