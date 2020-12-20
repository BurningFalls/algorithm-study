#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int N;
int arr[1001];
vector<int> v;

bool func() {
	int idx = 1;
	FOR(i, 1, N) {
		if (arr[i] == idx) {
			idx++;
		}
		else if (arr[i] != idx) {
			if (!v.empty() && v.back() == idx) {
				v.pop_back();
				idx++;
				i--;
			}
			else
				v.push_back(arr[i]);
		}
	}
	while (!v.empty()) {
		int node = v.back();
		v.pop_back();
		if (node == idx)
			idx++;
		else
			return false;
	}
	return true;
}

int main() {
	FASTIO;
	cin >> N;
	FOR(i, 1, N)
		cin >> arr[i];
	if (func())
		cout << "Nice";
	else
		cout << "Sad";

	return 0;
}