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
    string st, et;
    cin >> st >> et;
    int N, T;
    cin >> N >> T;
    
    int t1 = ((st[0] - '0') * 10 + (st[1] - '0')) * 60 + ((st[3] - '0') * 10 + (st[4] - '0'));
    int t2 = ((et[0] - '0') * 10 + (et[1] - '0')) * 60 + ((et[3] - '0') * 10 + (et[4] - '0'));
    int cnt = ((t2 - t1) % T == 0 ? (t2 - t1) / T - 1 : (t2 - t1) / T);
    int ans = N / cnt;
    int tim = t1 + T * (N % cnt + 1);
    cout << ans << "\n";
    int min = tim / 60;
    tim %= 60;
    int sec = tim;
    if (min < 10) {
        cout << 0;
    }
    cout << min << ':';
    if (sec < 10) {
        cout << 0;
    }
    cout << sec << "\n";
    
    return 0;
}


