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
    int N, M, K;
    cin >> N >> M >> K;
    map<string, int> mp;
    set<string> se;
    FOR(i, 1, N) {
        string s;
        int p;
        cin >> s >> p;
        mp[s] = p;
    }
    int score = 0;
    FOR(k, 1, K) {
        string s;
        cin >> s;
        score += mp[s];
        se.insert(s);
    }
    
    vector<int> v;
    for(auto &x : mp) {
        if (se.count(x.first)) continue;
        v.push_back(x.second);
    }
    sort(ALL(v));
    
    int score1 = score, score2 = score;
    FOR(i, 0, M - K - 1) {
        score1 += v[i];
    }
    ROF(i, N - K - 1, N - M) {
        score2 += v[i];
    }
    cout << score1 << " " << score2 << "\n";
    
    return 0;
}

