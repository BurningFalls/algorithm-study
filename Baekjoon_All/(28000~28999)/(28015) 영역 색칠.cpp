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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> Map(N, vector<int>(M + 1));
    FOR(i, 0, N - 1) {
        FOR(j, 0, M - 1) {
            cin >> Map[i][j];
        }
        Map[i][M] = 0;
    }

    int ans = 0;
    vector<int> tmp;
    FOR(i, 0, N - 1) {
        int one = 0, two = 0;
        FOR(j, 0, M) {
            if (!tmp.empty() && Map[i][j] == 0) {
                int one = 0, two = 0;
                int prev = -1;
                FOR(k, 0, LEN(tmp) - 1) {
                    if (prev != tmp[k]) {
                        one += (prev == 1);
                        two += (prev == 2);
                        prev = tmp[k];
                    }
                }
                one += (prev == 1);
                two += (prev == 2);
                ans += min(one, two) + 1;
                tmp.clear();
            }
            else if (Map[i][j] != 0) {
                tmp.push_back(Map[i][j]);
            }
        }
    }
    cout << ans;

    return 0;
}
