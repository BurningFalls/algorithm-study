#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>

int main() {
	FASTIO;
	int N, S, half;
	vector<int> v, first, second;
	cin >> N >> S;
	half = N / 2;
	
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < (1 << (N - half)); i++) {
		int sum = 0;
		for (int j = 0; j < N - half; j++) {
			if (i & (1 << j))
				sum += v[j];
		}
		first.push_back(sum);
	}
	for (int i = 0; i < (1 << half); i++) {
		int sum = 0;
		for (int j = 0; j < half; j++) {
			if (i & (1 << j))
				sum += v[j + (N - half)];
		}
		second.push_back(sum);
	}
	sort(first.begin(), first.end());
	sort(second.begin(), second.end(), greater<int>());

	int idx1 = 0, idx2 = 0;
	ll result = 0;
	while (idx1 < (1 << (N - half)) && idx2 < (1 << half)) {
		if (first[idx1] + second[idx2] == S) {
			ll cnt1 = 1, cnt2 = 1;
			idx1++, idx2++;
			while (idx1 < (1 << (N - half)) && first[idx1] == first[idx1 - 1]) {
				idx1++;
				cnt1++;
			}
			while (idx2 < (1 << half) && second[idx2] == second[idx2 - 1]) {
				idx2++;
				cnt2++;
			}
			result += cnt1 * cnt2;
		}
		else if (first[idx1] + second[idx2] < S)
			idx1++;
		else if (first[idx1] + second[idx2] > S)
			idx2++;
	}
	if (S == 0)
		result--;
	cout << result;

	return 0;
}