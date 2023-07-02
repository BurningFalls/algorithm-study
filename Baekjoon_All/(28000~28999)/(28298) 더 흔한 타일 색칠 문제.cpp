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
    vector<vector<char>> Map(N, vector<char>(M));
    FOR(i, 0, N - 1) {
        FOR(j, 0, M - 1) {
            cin >> Map[i][j];
        }
    }
    
    int ans = 0;
    int cnt = (N / K) * (M / K);
    FOR(i, 0, K - 1) {
        FOR(j, 0, K - 1) {
            map<char, int> mp;
            for(int y = i; y < N; y += K) {
                for(int x = j; x < M; x += K) {
                    mp[Map[y][x]]++;
                }
            }
            int maxi = 0;
            char c = '.';
            for(const auto &x: mp) {
                if (maxi < x.second) {
                    maxi = x.second;
                    c = x.first;
                }
            }
            for(int y = i; y < N; y += K) {
                for(int x = j; x < M; x += K) {
                    Map[y][x] = c;
                }
            }
            ans += (cnt - maxi);
        }
    }
    
    cout << ans << "\n";
    FOR(i, 0, N - 1) {
        FOR(j, 0, M - 1) {
            cout << Map[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}





