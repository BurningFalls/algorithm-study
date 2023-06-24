#include <bits/stdc++.h>
using namespace std;

#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
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
    vector<ll> v(N);
    FOR(i, 0, N - 1) {
        cin >> v[i];
    }
    FOR(i, 0, N - 1) {
        vector<ll> tmp;
        int cnt = 0;
        FOR(j, 0, 61) {
            if (v[i] & (1LL << j)) {
                cnt++;
                tmp.push_back(j);
            }
        }
        if (cnt == 1) {
            cout << tmp[0] - 1 << " " << tmp[0] - 1 << "\n";
        }
        else if (cnt == 2) {
            cout << tmp[0] << " " << tmp[1] << "\n";
        }
    }
    
    return 0;
}



