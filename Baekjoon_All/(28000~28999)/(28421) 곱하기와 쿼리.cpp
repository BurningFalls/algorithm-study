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
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N + 1);
    vector<int> cnt(10001, 0);
    bool zero_flag = false;
    FOR(i, 1, N) {
        cin >> A[i];
        cnt[A[i]]++;
    }
    
    FOR(q, 1, Q) {
        int kind, x, idx;
        cin >> kind;
        if (kind == 1) {
            cin >> x;
            if (N == 1) {
                cout << 0 << "\n";
                continue;
            }
            if (x == 0) {
                cout << (zero_flag ? 1 : 0) << "\n";
                continue;
            }
            bool flag = false;
            FOR(i, 1, (int)sqrt(x)) {
                if (cnt[i] == 0) continue;
                if (x % i != 0) continue;
                if (i * i == x && cnt[i] < 2) continue;
                if (x / i > 10000 || cnt[x / i] == 0) continue;
                flag = true;
                break;
            }
            cout << (flag ? 1 : 0) << "\n";
        }
        else if (kind == 2) {
            cin >> idx;
            cnt[A[idx]]--;
            A[idx] = 0;
            zero_flag = true;
        }
    }
    
    return 0;
}
