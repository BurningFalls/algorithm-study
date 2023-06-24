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
    vector<vector<int>> v(N, vector<int>(5));
    FOR(i, 0, N - 1) {
        FOR(j, 0, 4) {
            cin >> v[i][j];
        }
    }
    string tmp = "00011";
    bool flag = true;
    int maxi = 0;
    string max_str = "00011";
    while(flag) {
        int cnt = 0;
        FOR(i, 0, N - 1) {
            int k = 0;
            FOR(j, 0, 4) {
                k += ((tmp[j] - '0') && v[i][j]);
            }
            cnt += (k >= 2);
        }
        if (cnt > maxi) {
            maxi = cnt;
            max_str = tmp;
        }
        flag = next_permutation(ALL(tmp));
    }
    cout << maxi << "\n";
    FOR(i, 0, 4) {
        cout << max_str[i] << " ";
    }
    cout << "\n";
    
    return 0;
}



