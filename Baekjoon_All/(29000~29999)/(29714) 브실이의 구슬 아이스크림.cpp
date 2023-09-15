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
    int N;
    cin >> N;
    vector<int> color(N);
    map<int, int> mp;
    FOR(i, 0, N - 1) {
        cin >> color[i];
        mp[color[i]]++;
    }
    
    int Q;
    cin >> Q;
    FOR(q, 1, Q) {
        int A, B;
        cin >> A;
        map<int, int> tmp;
        FOR(i, 1, A) {
            int x;
            cin >> x;
            tmp[x]++;
        }
        cin >> B;
        vector<int> vb(B);
        FOR(i, 0, B - 1) {
            cin >> vb[i];
        }
        
        bool flag = true;
        for(auto &n : tmp) {
            flag &= (n.second <= mp[n.first]);
        }
        if (flag) {
            for(auto &n : tmp) {
                if (n.second <= mp[n.first]) {
                    mp[n.first] -= n.second;
                }
            }
            FOR(i, 0, B - 1) {
                mp[vb[i]]++;
            }
        }
    }
    
    int sum = 0;
    for(auto &n : mp) {
        sum += n.second;
    }
    cout << sum << "\n";
    for(auto &n : mp) {
        FOR(i, 1, n.second) {
            cout << n.first << " ";
        }
    }
    cout << "\n";
    
    return 0;
}

