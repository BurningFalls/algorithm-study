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
    vector<vector<int>> v(N, vector<int>(7));
    vector<int> score(N, 0);
    FOR(i, 0, N - 1) {
        FOR(j, 0, 6) {
            cin >> v[i][j];
        }
    }
    FOR(i, 0, N - 1) {
        score[i] += max(v[i][0], v[i][1]);
        vector<int> tmp;
        FOR(j, 2, 6) {
            tmp.push_back(v[i][j]);
        }
        sort(ALL(tmp), greater<int>());
        score[i] += tmp[0] + tmp[1];
    }
    
    int maxi = 0;
    FOR(i, 0, N - 1) {
        maxi = max(maxi, score[i]);
    }
    
    cout << maxi << "\n";
    
    
    return 0;
}



