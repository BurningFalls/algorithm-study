#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int N;
	string NAME[3] = { "Adrian", "Bruno", "Goran" };
	string real_ans;
	string ans[3] = { "", "", "" };
	int cnt[3] = { 0, };
	char temp0[7] = { 'A', 'B', 'C', 'A', 'B', 'C' };
	char temp1[5] = { 'B', 'A', 'B', 'C' };
	char temp2[7] = { 'C', 'C', 'A', 'A', 'B', 'B' };
	int maximum;
	cin >> N;
	cin >> real_ans;

	for (int i = 0; i < N; i++) {
		ans[0] += temp0[i % 6];
		ans[1] += temp1[i % 4];
		ans[2] += temp2[i % 6];
	}

	for (int i = 0; i < N; i++) {
		if (ans[0][i] == real_ans[i])
			cnt[0]++;
		if (ans[1][i] == real_ans[i])
			cnt[1]++;
		if (ans[2][i] == real_ans[i])
			cnt[2]++;
	}

	maximum = max({ cnt[0], cnt[1], cnt[2] });
	cout << maximum << "\n";
	for (int i = 0; i < 3; i++) {
		if (maximum == cnt[i])
			cout << NAME[i] << "\n";
	}


	return 0;
}