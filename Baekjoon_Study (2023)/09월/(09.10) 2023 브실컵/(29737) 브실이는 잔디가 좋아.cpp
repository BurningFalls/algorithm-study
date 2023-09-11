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
#define MOD 1000000007

struct NODE {
    string name;
    int max_len;
    int fre_cnt;
    int st_date;
    int fail_cnt;
    
    bool operator< (const NODE &n) const {
        if (max_len == n.max_len) {
            if (fre_cnt == n.fre_cnt) {
                if (st_date == n.st_date) {
                    if (fail_cnt == n.fail_cnt) {
                        return name < n.name;
                    }
                    return fail_cnt < n.fail_cnt;
                }
                return st_date < n.st_date;
            }
            return fre_cnt < n.fre_cnt;
        }
        return max_len > n.max_len;
    }
};

bool Compare(NODE& n1, NODE& n2) {
    bool flag = true;
    flag &= (n1.max_len == n2.max_len);
    flag &= (n1.fre_cnt == n2.fre_cnt);
    flag &= (n1.st_date == n2.st_date);
    flag &= (n1.fail_cnt == n2.fail_cnt);
    return flag;
}

int main() {
    FASTIO;
    int N, W;
    cin >> N >> W;
    vector<string> name(N);
    vector<vector<vector<char>>> Map(N, vector<vector<char>>(7, vector<char>(W)));
    FOR(i, 0, N - 1) {
        cin >> name[i];
        FOR(j, 0, 6) {
            FOR(k, 0, W - 1) {
                cin >> Map[i][j][k];
            }
        }
    }
    
    vector<NODE> ansv;
    
    FOR(k, 0, N - 1) {
        vector<string> v;
        vector<int> dv;
        string s = "";
        int date = 0;
        int fail_cnt = 0;
        FOR(j, 0, W - 1) {
            FOR(i, 0, 6) {
                if (Map[k][i][j] == 'O') {
                    s += 'O';
                    if (date == 0) {
                        date = 7 * j + i + 1;
                    }
                }
                else if (Map[k][i][j] == 'X') {
                    fail_cnt++;
                    while(!s.empty() && s.back() == 'F') {
                        s.pop_back();
                    }
                    if (!s.empty()) {
                        v.push_back(s);
                        dv.push_back(date);
                    }
                    s = "";
                    date = 0;
                }
                else if (Map[k][i][j] == 'F') {
                    if (s.empty()) continue;
                    s += 'F';
                }
            }
        }
        while(!s.empty() && s.back() == 'F') {
            s.pop_back();
        }
        if (!s.empty()) {
            v.push_back(s);
            dv.push_back(date);
        }
        
        vector<NODE> nv;
        FOR(i, 0, LEN(v) - 1) {
            int len = LEN(v[i]);
            int fre_cnt = 0;
            int st_date = dv[i];
            FOR(j, 0, LEN(v[i]) - 1) {
                if (v[i][j] == 'F') {
                    fre_cnt++;
                }
            }
            nv.push_back({".", len - fre_cnt, fre_cnt, st_date, 0});
        }
        
        sort(ALL(nv));
        
        if (nv.empty()) {
            ansv.push_back({name[k], 0, 0, 0, fail_cnt});
        }
        else {
            ansv.push_back({name[k], nv[0].max_len, nv[0].fre_cnt, nv[0].st_date, fail_cnt});
        }
    }
    
    sort(ALL(ansv));
    
    int rank = 1;
    FOR(i, 0, LEN(ansv) - 1) {
        cout << rank << ". " << ansv[i].name << "\n";
        if ((i != LEN(ansv) - 1) && !Compare(ansv[i], ansv[i + 1])) {
            rank++;
        }
    }
    
    return 0;
}

