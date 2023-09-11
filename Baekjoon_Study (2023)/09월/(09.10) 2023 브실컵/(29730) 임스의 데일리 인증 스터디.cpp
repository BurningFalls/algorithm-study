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

bool compare(string s1, string s2) {
    if (LEN(s1) >= 4 && LEN(s2) >= 4 && s1[3] == '.' && s2[3] == '.') {
        int n1 = stoi(s1.substr(7));
        int n2 = stoi(s2.substr(7));
        return n1 < n2;
    }
    else if (LEN(s1) >= 4 && s1[3] == '.') {
        return false;
    }
    else if (LEN(s2) >= 4 && s2[3] == '.') {
        return true;
    }
    else {
        if (LEN(s1) == LEN(s2)) {
            return s1 < s2;
        }
        else {
            return LEN(s1) < LEN(s2);
        }
    }
}

int main() {
    FASTIO;
    int N;
    cin >> N;
    vector<string> s(N);
    cin.ignore();
    FOR(i, 0, N - 1) {
        getline(cin, s[i]);
    }
    
    sort(ALL(s), compare);
    FOR(i, 0, N - 1) {
        cout << s[i] << "\n";
    }
    
    return 0;
}

