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
    vector<ll> A(N + 2);
    FOR(i, 1, N) {
        cin >> A[i];
    }
    
    ll all_sum = 0;
    vector<ll> v(N + 1, 0);
    FOR(i, 1, N - 1) {
        v[i] = A[i + 1] - A[i];
        all_sum += v[i];
    }
    
    vector<ll> Lsum(N + 1, 0), Rsum(N + 1, 0);
    FOR(i, 1, N - 1) {
        Lsum[i] = Lsum[i - 1] + v[i];
    }
    ROF(i, N - 1, 1) {
        Rsum[i] = Rsum[i + 1] + v[i];
    }
    
    vector<ll> Lmini(N + 1, LINF), Rmini(N + 1, LINF);
    FOR(i, 1, N - 1) {
        Lmini[i] = min(Lmini[i - 1], Lsum[i]);
    }
    ROF(i, N - 1, 1) {
        Rmini[i] = min(Rmini[i + 1], Rsum[i]);
    }
    
    ll mini = 0;
    FOR(i, 0, M) {
        int left = 1 + i - 1;
        int right = N - (M - i);
        ll sum = 0;
        if (i == 0) {
            sum = Rmini[right];
        }
        else if (i == M) {
            sum = Lmini[left];
        }
        else {
            sum = Lmini[left] + Rmini[right];
        }
        mini = min(mini, sum);
    }
    
    cout << all_sum - mini << "\n";
    
    return 0;
}

