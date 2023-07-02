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
#define PI 3.1415926535

struct NODE {
    double x;
    double y;
    double r;
};

struct NODE2 {
    double d;
    int n1;
    int n2;
    
    bool operator<(const NODE2 n) const{
        return d > n.d;
    }
};

vector<int> Parent(1001);

int Find(int node) {
    if (Parent[node] == node)
        return node;
    return Parent[node] = Find(Parent[node]);
}

bool is_Same(int n1, int n2) {
    n1 = Find(n1);
    n2 = Find(n2);
    return n1 == n2;
}

void Union(int n1, int n2) {
    n1 = Find(n1);
    n2 = Find(n2);
    Parent[min(n1, n2)] = max(n1, n2);
}

int main() {
    FASTIO;
    int N;
    cin >> N;
    vector<NODE> v(N);
    vector<vector<double>> chain(N, vector<double>(N));
    FOR(i, 0, N - 1) {
        cin >> v[i].x >> v[i].y >> v[i].r;
    }
    FOR(i, 0, N - 1) {
        FOR(j, 0, N - 1) {
            double mdiff = sqrt(pow((v[i].x - v[j].x), 2) + pow((v[i].y - v[j].y), 2));
            if (mdiff <= v[i].r + v[j].r) {
                chain[i][j] = 0;
                continue;
            }
            double rdiff = abs(v[i].r - v[j].r);
            double dist1 = sqrt(pow(mdiff, 2) - pow(rdiff, 2));
            if (rdiff == 0) {
                chain[i][j] = dist1 * 2 + 2 * PI * v[i].r;
                continue;
            }
            double angle = acos(rdiff / mdiff);
            double dist2 = 2 * PI * max(v[i].r, v[j].r) * ((2 * PI - 2 * angle) / (2 * PI));
            double dist3 = 2 * PI * min(v[i].r, v[j].r) * ((2 * angle) / (2 * PI));
            chain[i][j] = dist1 * 2 + dist2 + dist3;
        }
    }
    
    FOR(i, 0, N - 1) {
        Parent[i] = i;
    }
    PQ<NODE2> pq;
    FOR(i, 0, N - 1) {
        FOR(j, i + 1, N - 1) {
            pq.push({chain[i][j], i, j});
        }
    }
    double ans = 0;
    while(!pq.empty()) {
        NODE2 x = pq.top();
        pq.pop();
        if (!is_Same(x.n1, x.n2)) {
            Union(x.n1, x.n2);
            ans += x.d;
        }
    }
    cout << fixed << setprecision(6);
    cout << ans;
    
    return 0;
}





