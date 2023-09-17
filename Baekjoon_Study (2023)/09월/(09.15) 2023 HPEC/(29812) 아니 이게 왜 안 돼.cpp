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
    vector<char> S(N);
    vector<char> v = {'H', 'Y', 'U'};
    vector<int> cntv(3, 0);
    FOR(i, 0, N - 1) {
        cin >> S[i];
        FOR(j, 0, 2) {
            if (S[i] == v[j]) {
                cntv[j]++;
            }
        }
    }
    int mini = INF;
    FOR(i, 0, 2) {
        mini = min(mini, cntv[i]);
    }
    int D, M;
    cin >> D >> M;
    
    int sum = 0;
    int cnt = 0;
    FOR(i, 0, N - 1) {
        if (S[i] == 'H' || S[i] == 'Y' || S[i] == 'U') {
            sum += min(D * cnt, D + M);
            cnt = 0;
        }
        else {
            cnt++;
        }
    }
    sum += min(D * cnt, D + M);
    
    if (sum == 0) {
        cout << "Nalmeok";
    }
    else {
        cout << sum;
    }
    cout << "\n";
    if (mini == 0) {
        cout << "I love HanYang University";
    }
    else {
        cout << mini;
    }
    cout << "\n";
    
    return 0;
}



