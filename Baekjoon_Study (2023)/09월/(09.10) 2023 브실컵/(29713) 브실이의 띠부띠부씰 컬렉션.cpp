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
    string s;
    cin >> s;
    vector<int> cnt(26, 0), cnt2(26, 0);
    string tmp = "BRONZESILVER";
    FOR(i, 0, LEN(tmp) - 1) {
        cnt[tmp[i] - 'A']++;
    }
    FOR(i, 0, LEN(s) - 1) {
        cnt2[s[i] - 'A']++;
    }
    
    int mini = INF;
    FOR(i, 0, 25) {
        if (cnt[i] == 0) continue;
        mini = min(mini, cnt2[i] / cnt[i]);
    }
    cout << (mini == INF? 0 : mini) << "\n";
    
    return 0;
}


