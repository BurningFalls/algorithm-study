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
    ll odd_sum = 0, even_sum = 0;
    FOR(i, 1, N) {
        ll num;
        cin >> num;
        odd_sum += num * (i % 2 == 1);
        even_sum += num * (i % 2 == 0);
    }
    
    if (N == 3) {
        cout << (odd_sum > even_sum ? -1 : even_sum - odd_sum);
    }
    else {
        cout << abs(odd_sum - even_sum);
    }
    
    return 0;
}




