#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string name;
	int g_cnt, b_cnt;
	int len;
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		getline(cin, name);
		g_cnt = 0, b_cnt = 0;
		len = name.size();
		cout << name << " is ";
		for (int j = 0; j < len; j++) {
			if (name[j] == 'g' || name[j] == 'G')
				g_cnt++;
			else if (name[j] == 'b' || name[j] == 'B')
				b_cnt++;
		}
		if (g_cnt > b_cnt)
			cout << "GOOD\n";
		else if (g_cnt < b_cnt)
			cout << "A BADDY\n";
		else if (g_cnt == b_cnt)
			cout << "NEUTRAL\n";
	}

	return 0;
}