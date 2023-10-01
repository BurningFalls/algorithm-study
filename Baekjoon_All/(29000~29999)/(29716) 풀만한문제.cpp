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
    int J, N;
    cin >> J >> N;
    cin.ignore();
    
    int cnt = 0;
    FOR(i, 1, N) {
        string s;
        getline(cin, s);
        int sum = 0;
        FOR(j, 0, LEN(s) - 1) {
            if (s[j] >= 'A' && s[j] <= 'Z') {
                sum += 4;
            }
            else if ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9')) {
                sum += 2;
            }
            else if (s[j] == ' ') {
                sum += 1;
            }
        }
        cnt += (sum <= J);
    }
    cout << cnt << "\n";
    
    return 0;
}


