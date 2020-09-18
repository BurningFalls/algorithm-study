#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int len;
int arr[52];
int ans[3];
string minimum = "";
string str;

void DFS(int node, int cnt) {
	if (cnt == 2) {
		string sub_str[3];
		string ch_str = "";
		sub_str[0] = str.substr(0, ans[0]);
		sub_str[1] = str.substr(ans[0], ans[1] - ans[0]);
		sub_str[2] = str.substr(ans[1]);
		for (int i = 0; i < 3; i++) {
			reverse(sub_str[i].begin(), sub_str[i].end());
			ch_str += sub_str[i];
		}
		if (minimum == "")
			minimum = ch_str;
		else
			minimum = min(minimum, ch_str);

		return;
	}

	for (int i = node; i < len; i++) {
		ans[cnt] = i;
		DFS(i + 1, cnt + 1);
	}
}

int main() {
	cin >> str;
	len = str.size();
	for (int i = 1; i < len; i++) {
		arr[i] = i;
	}
	DFS(1, 0);
	cout << minimum;

	return 0;
}