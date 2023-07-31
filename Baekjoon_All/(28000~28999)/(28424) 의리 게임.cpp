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
#define MAX 100002

vector<int> Parent(MAX);

int Find(int node) {
    if (Parent[node] == node)
        return node;
    return Parent[node] = Find(Parent[node]);
}

void Union(int n1, int n2) {
    n1 = Find(n1);
    n2 = Find(n2);
    Parent[n1] = n2;
}

int main() {
    FASTIO;
    int N, Q;
    cin >> N >> Q;
    FOR(i, 1, N + 1) {
        Parent[i] = i;
    }
    vector<int> M(N + 2, 0);
    vector<int> drink(N + 2, 0);
    FOR(i, 1, N) {
        cin >> M[i];
    }
    
    FOR(q, 1, Q) {
        int kind;
        cin >> kind;
        if (kind == 1) {
            int idx, x;
            cin >> idx >> x;
            int p = idx;
            while(p <= N && x > 0) {
                p = Find(p);
                if (p > N) break;
                int rest = M[p] - drink[p];
                if (x >= rest) {
                    drink[p] = M[p];
                    x -= rest;
                    p++;
                }
                else if (x < rest) {
                    drink[p] += x;
                    x = 0;
                    break;
                }
            }
            Union(idx, p);
        }
        else if (kind == 2) {
            int idx;
            cin >> idx;
            cout << drink[idx] << "\n";
        }
    }
    
    return 0;
}
