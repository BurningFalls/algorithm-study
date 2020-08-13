#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
int ans[9];
int maximum = -1;

void DFS(int end, int cnt) {
	if (end == cnt) {
		int num = 0;
		for (int i = 0; i < end; i++) {
			num += ans[i] * int(pow(10, end - i - 1));
		}
		if (N >= num) {
			cout << num;
			exit(0);
		}
		return;
	}
	for (int i = 7; i >= 4; i -= 3) {
		ans[cnt] = i;
		DFS(end, cnt + 1);
	}
}

int main() {
	int len;
	cin >> N;
	len = to_string(N).size();
	DFS(len, 0);
	DFS(len - 1, 0);

	return 0;
}