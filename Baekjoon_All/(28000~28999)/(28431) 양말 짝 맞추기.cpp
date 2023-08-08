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
    vector<int> cnt(10, 0);
    FOR(i, 1, 5) {
        int num;
        cin >> num;
        cnt[num]++;
    }
    int ans = 0;
    FOR(i, 0, 9) {
        if (cnt[i] % 2 == 1) {
            ans = i;
            break;
        }
    }
    cout << ans;
    
    
    return 0;
}
