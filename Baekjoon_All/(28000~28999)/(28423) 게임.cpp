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

int Change(int x) {
    string s = to_string(x);
    int sum = 0;
    int mult = 1;
    FOR(i, 0, LEN(s) - 1) {
        sum += s[i] - '0';
        mult *= s[i] - '0';
    }
    return sum * pow(10, LEN(to_string(mult))) + mult;
}

int main() {
    FASTIO;
    int L, R;
    cin >> L >> R;
    
    int ans = 0;
    FOR(i, L, R) {
        set<int> s;
        int num = i;
        bool flag = true;
        while(!s.count(num)) {
            s.insert(num);
            int ch = Change(num);
            if (ch > 100000) {
                flag = false;
                break;
            }
            num = ch;
        }
        if (!flag) {
            ans -= 1;
        }
        else if (num == Change(num)) {
            ans += 1;
        }
    }
    cout << ans << "\n";
    
    return 0;
}
