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
    string s;
    cin >> s;
    int N;
    cin >> N;
    int y = stoi(s.substr(0, 4));
    int m = stoi(s.substr(5, 2));
    int d = stoi(s.substr(8, 2));
    int t = y * 360 + (m - 1) * 30 + (d - 1);
    t += N;
    
    y = t / 360;
    t %= 360;
    m = t / 30;
    t %= 30;
    d = t;
    
    m += 1;
    d += 1;
    
    cout << y << '-';
    if (m < 10) {
        cout << 0;
    }
    cout << m << '-';
    if (d < 10) {
        cout << 0;
    }
    cout << d;
    cout << "\n";
    
    return 0;
}


