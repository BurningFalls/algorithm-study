#include <iostream>
using namespace std;

int main() {
	int L;
	char temp;
	long long int cnt[4] = { 0, };
	long long int ans = 1;
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> temp;
		if (temp == 'A')
			cnt[0]++;
		else if (temp == 'C')
			cnt[1]++;
		else if (temp == 'G')
			cnt[2]++;
		else if (temp == 'T')
			cnt[3]++;
	}
	for (int i = 0; i < 4; i++) {
		ans = (ans * cnt[i]) % 1000000007;
	}
	cout << ans;

	return 0;
}