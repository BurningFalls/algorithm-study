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
    vector<string> S(N);
    set<string> se;
    int idx = 0;
    FOR(i, 0, N - 1) {
        cin >> S[i];
        se.insert(S[i]);
        if (S[i] == "?") {
            idx = i;
        }
    }
    
    int M;
    cin >> M;
    vector<string> A(M);
    FOR(i, 0, M - 1) {
        cin >> A[i];
    }
    if (N == 1) {
        cout << A[0];
        return 0;
    }
    string ans = "";
    FOR(i, 0, M - 1) {
        string s = A[i];
        if (se.count(s)) continue;
        if (idx == 0) {
            if (s[LEN(s) - 1] == S[1][0]) {
                ans = s;
            }
        }
        else if (idx == N - 1) {
            if (S[N - 2][LEN(S[N - 2]) - 1] == s[0]) {
                ans = s;
            }
        }
        else {
            if (S[idx - 1][LEN(S[idx - 1]) - 1] == s[0] && s[LEN(s) - 1] == S[idx + 1][0]) {
                ans = s;
            }
        }
    }
    cout << ans;
    
    return 0;
}

