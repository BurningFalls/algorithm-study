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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    FOR(i, 0, N - 1) {
        cin >> A[i];
    }
    sort(ALL(A));
    
    int ans = N;
    int left = 1, right = N;
    while(left <= right) {
        int mid = (left + right) / 2;
        queue<pii> q;
        int len = 0;
        bool flag = true;
        FOR(i, 0, N - 1) {
            if (len == mid) {
                int t = q.front().second;
                q.pop();
                len--;
                if (A[i] < t + 1) {
                    flag = false;
                    break;
                }
                else if (t + 1 <= A[i] && A[i] <= t + K) {
                    q.push({t + 1, t + K});
                    len++;
                }
                else if (t + K < A[i]) {
                    q.push({A[i] - K + 1, A[i]});
                    len++;
                }
            }
            else if (len < mid) {
                if (A[i] - K + 1 < 1) {
                    q.push({1, K});
                    len++;
                }
                else {
                    q.push({A[i] - K + 1, A[i]});
                    len++;
                }
            }
        }
        if (flag) {
            ans = min(ans, mid);
            right = mid - 1;
        }
        else if (!flag) {
            left = mid + 1;
        }
    }
    cout << ans;
    
    return 0;
}





