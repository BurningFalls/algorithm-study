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

struct NODE {
    int x;
    int y;
    
    bool operator< (const NODE &n) const {
        if (x == n.x)
            return y < n.y;
        return x < n.x;
    }
};

int main() {
    FASTIO;
    int S;
    cin >> S;
    vector<int> v1 = {508, 108};
    vector<int> v2 = {212, 305};
    vector<NODE> ans;
    FOR(a, 0, 200) {
        FOR(b, 0, 200) {
            bool flag = false;
            FOR(i, 0, 1) {
                FOR(j, 0, 1) {
                    if ((a * v1[i] + b * v2[j]) * 4763 == S) {
                        flag = true;
                    }
                }
            }
            if (flag) {
                ans.push_back({a, b});
            }
        }
    }
    
    sort(ALL(ans));
    if (ans.empty()) {
        cout << "0\n";
    }
    else {
        cout << LEN(ans) << "\n";
        FOR(i, 0, LEN(ans) - 1) {
            cout << ans[i].x << " " << ans[i].y << "\n";
        }
    }
    
    
    return 0;
}



