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
#define MAX 5000

ll Gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return Gcd(b, a % b);
}

int main() {
    FASTIO;
    ll n, a, b;
    cin >> n >> a >> b;

    ll gcd = Gcd(a, a + b);
    if (gcd == 1) {
        cout << "Yes\n";
        ll n1 = a, n2 = a + b;
        FOR(i, 1, n) {
            cout << n1 << " " << n2 << "\n";
            n1 += 2 * b;
            n2 += 2 * b;
        }
    }
    else if (gcd != 1) {
        cout << "No\n";
    }

    return 0;
}
