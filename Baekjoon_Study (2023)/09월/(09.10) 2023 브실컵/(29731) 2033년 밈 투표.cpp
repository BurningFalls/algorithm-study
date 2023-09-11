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
    set<string> s;
    s.insert("Never gonna give you up");
    s.insert("Never gonna let you down");
    s.insert("Never gonna run around and desert you");
    s.insert("Never gonna make you cry");
    s.insert("Never gonna say goodbye");
    s.insert("Never gonna tell a lie and hurt you");
    s.insert("Never gonna stop");
    
    int N;
    cin >> N;
    bool flag = true;
    cin.ignore();
    FOR(i, 1, N) {
        string t;
        getline(cin, t);
        flag &= (s.count(t));
    }
    
    cout << (flag ? "No" : "Yes");
    
    return 0;
}


