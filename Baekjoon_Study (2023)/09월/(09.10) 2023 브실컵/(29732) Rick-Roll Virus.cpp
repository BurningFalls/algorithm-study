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
    vector<char> v(N + 1);
    vector<int> sum(N + 1, 0);
    int ans = 0;
    FOR(i, 1, N) {
        cin >> v[i];
    }
    FOR(i, 1, N) {
        sum[i] = sum[i - 1] + (v[i] == 'R');
    }
    FOR(i, 1, N) {
        int left = max(1, i - K);
        int right = min(N, i + K);
        int cnt = sum[right] - sum[left - 1];
        ans += (cnt != 0);
    }
    
    cout << (ans <= M ? "Yes" : "No") << "\n";
    
    return 0;
}


