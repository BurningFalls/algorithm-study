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
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    int p1 = a * d * d;
    int p2 = 2 * a * d * e + b * d;
    int p3 = a * e * e + b * e + c;
    int g1 = a * d;
    int g2 = b * d;
    int g3 = c * d + e;
    
    int A = p1 - g1;
    int B = p2 - g2;
    int C = p3 - g3;
    if (A == 0 && B == 0) {
        cout << (C == 0 ? "Nice" : "Head on");
    }
    else if (A == 0) {
        cout << "Remember my character";
    }
    else {
        int result = B * B - 4 * A * C;
        if (result > 0) {
            cout << "Go ahead";
        }
        else if (result == 0) {
            cout << "Remember my character";
        }
        else if (result < 0) {
            cout << "Head on";
        }
    }
    
    return 0;
}
