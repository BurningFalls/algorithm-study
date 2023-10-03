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
    vector<vector<int>> Q(N, vector<int>(M));
    vector<int> sum(M, 0);
    FOR(i, 0, N - 1) {
        FOR(j, 0, M - 1) {
            cin >> Q[i][j];
        }
    }
    int A;
    cin >> A;
    
    FOR(j, 0, M - 1) {
        FOR(i, 0, N - 1) {
            sum[j] += Q[i][j];
        }
    }
    FOR(i, 1, M - 1) {
        sum[i] = sum[i - 1] + sum[i];
    }
    
    int maxi = 0;
    FOR(i, 0, M - A) {
        int left = i;
        int right = left + A - 1;
        int cnt = sum[right] - (left == 0 ? 0 : sum[left - 1]);
        maxi = max(maxi, cnt);
    }
    cout << maxi << "\n";
    
    return 0;
}

