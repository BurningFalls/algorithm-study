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
#define MAX 400003

int N, M;
vector<int> Parent(MAX);
vector<vector<int>> Group(MAX, vector<int>());

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
    Parent[max(n1, n2)] = min(n1, n2);
}

int main() {
    FASTIO;
    cin >> N >> M;
    vector<pii> v(M);
    FOR(i, 0, M - 1) {
        cin >> v[i].first >> v[i].second;
    }
    int X;
    cin >> X;
    FOR(i, 1, MAX - 1) {
        Parent[i] = i;
    }
    
    int idx = N + 1;
    FOR(i, 0, M - 1) {
        if (v[i].first == X) {
            v[i].first = idx;
            idx++;
        }
        else if (v[i].second == X) {
            v[i].second = idx;
            idx++;
        }
    }
    
    FOR(i, 0, M - 1) {
        int A = v[i].first;
        int B = v[i].second;
        if (!is_Same(A, B)) {
            Union(A, B);
        }
    }
    
    int maxi = 0;
    FOR(i, 1, idx - 1) {
        int p = Find(i);
        maxi = max(maxi, p);
        Group[p].push_back(i);
    }
    
    int ans = 0;
    FOR(i, 1, maxi) {
        if (Group[i].empty()) continue;
        int cnt = 0;
        FOR(j, 0, LEN(Group[i]) - 1) {
            if (Group[i][j] > N) {
                cnt++;
            }
        }
        if (cnt >= 2) {
            ans = max(ans, LEN(Group[i]) - cnt);
        }
        else {
            ans = max(ans, LEN(Group[i]));
        }
    }
    cout << ans << "\n";
    
    return 0;
}



