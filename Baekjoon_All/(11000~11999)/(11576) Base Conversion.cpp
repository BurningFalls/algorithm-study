#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int arr[26];
vector<int> v;

int main() {
	FASTIO;
	int A, B;
	cin >> A >> B;
	int M;
	int ten = 0;
	cin >> M;
	FOR(i, 1, M) {
		cin >> arr[i];
	}
	ROF(i, M, 1) {
		ten += arr[i] * pow(A, M - i);
	}
	while (ten > 0) {
		int temp = ten / B;
		v.push_back(ten - B * temp);
		ten = temp;
	}
	int len = v.size();
	ROF(i, v.size() - 1, 0) {
		cout << v[i] << " ";
	}


	return 0;
}