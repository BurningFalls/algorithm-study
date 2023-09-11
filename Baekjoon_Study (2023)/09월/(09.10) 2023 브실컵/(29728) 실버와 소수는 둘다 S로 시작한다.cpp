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

vector<bool> is_prime(5000001, 1);

void Find_Prime() {
    is_prime[1] = 0;
    int sqrtx = sqrt(5000000);
    FOR(i, 2, sqrtx) {
        if (!is_prime[i]) continue;
        for(int j = i * 2; j <= 5000000; j += i) {
            is_prime[j] = 0;
        }
    }
}

int main() {
    FASTIO;
    Find_Prime();
    int N;
    cin >> N;
    bool back = true;
    char fc = '.';
    char ec = '.';
    int bcnt = 0;
    int scnt = 0;
    FOR(i, 1, N) {
        if (is_prime[i]) {
            if (back) {
                if (ec == 'B') {
                    ec = 'S';
                    bcnt -= 1;
                    scnt += 2;
                }
                else {
                    ec = 'S';
                    scnt += 1;
                }
                back = !back;
            }
            else if (!back) {
                if (fc == 'B') {
                    fc = 'S';
                    bcnt -= 1;
                    scnt += 2;
                }
                else {
                    fc = 'S';
                    scnt += 1;
                }
                back = !back;
            }
        }
        else if (!is_prime[i]) {
            if (back) {
                ec = 'B';
            }
            else if (!back) {
                fc = 'B';
            }
            bcnt += 1;
        }
    }
    
    cout << bcnt << " " << scnt << "\n";
    
    
    return 0;
}

