#include <iostream>
#include <string>
using namespace std;

string str;
bool flag;
int len;
char letters[5] = { 'U', 'C', 'P', 'C' };

void DFS(int node, int cnt) {
	if (cnt == 4) {
		flag = true;
		return;
	}
	for (int i = node; i < len; i++) {
		if (str[i] == letters[cnt]) {
			DFS(i + 1, cnt + 1);
		}
	}
}

int main() {
	flag = false;
	getline(cin, str);
	len = str.size();
	DFS(0, 0);
	if (flag)
		cout << "I love UCPC";
	else if (!flag)
		cout << "I hate UCPC";

	return 0;
}