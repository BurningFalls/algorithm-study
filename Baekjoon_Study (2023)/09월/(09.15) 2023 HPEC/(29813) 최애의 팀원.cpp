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

struct NODE {
    string x;
    int y;
};

int main() {
    FASTIO;
    int N;
    cin >> N;
    queue<NODE> q;
    FOR(i, 0, N - 1) {
        string a;
        int b;
        cin >> a >> b;
        q.push({a, b});
    }
    
    while(LEN(q) >= 3) {
        NODE n = q.front();
        q.pop();
        int cnt = (n.y - 1) % LEN(q);
        FOR(i, 1, cnt) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    cout << q.front().x << "\n";
    
    return 0;
}



