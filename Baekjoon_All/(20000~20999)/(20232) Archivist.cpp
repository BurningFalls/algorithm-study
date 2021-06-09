#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

string arr[25] =
{ "ITMO" , "SPbSU" , "SPbSU" , "ITMO" , "ITMO" ,"SPbSU",
"ITMO" , "ITMO" , "ITMO" , "ITMO" , "ITMO" , "PetrSU, ITMO" ,
"SPbSU" , "SPbSU" , "ITMO" , "ITMO" , "ITMO" , "ITMO" ,
"SPbSU", "ITMO", "ITMO", "ITMO", "ITMO","SPbSU",
"ITMO" };

int main() {
	FASTIO;
	int N;
	cin >> N;
	cout << arr[N - 1995];


	return 0;
}