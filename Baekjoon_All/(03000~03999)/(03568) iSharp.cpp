#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FOR(i, a, b) for(int i=a;i<=b;i++)
#define ROF(i, a, b) for(int i=a;i>=b;i--)
#define pii pair<int, int>
#define ll long long int

int main() {
	FASTIO;
	string all_sen;
	getline(cin, all_sen);
	int all_len = all_sen.size();
	string front_sen = "";
	string back_sen1 = "", back_sen2 = "";
	int node = 0;
	FOR(i, 0, all_len - 2) {
		if (all_sen[i] == ' ') {
			node = i + 1;
			break;
		}
		else
			front_sen += all_sen[i];
	}
	FOR(i, node, all_len - 1) {
		if ((all_sen[i] >= 'a' && all_sen[i] <= 'z') ||
			(all_sen[i] >= 'A' && all_sen[i] <= 'Z')) {
			back_sen1 += all_sen[i];
		}
		else if (all_sen[i] == ',' || all_sen[i] == ';') {
			int len_b2 = back_sen2.size();
			cout << front_sen;
			ROF(j, len_b2 - 1, 0) {
				if (back_sen2[j] == '[')
					cout << ']';
				else if (back_sen2[j] == ']')
					cout << '[';
				else
					cout << back_sen2[j];
			}
			cout << " " << back_sen1 << ";\n";
			back_sen1 = "";
			back_sen2 = "";
		}
		else if (all_sen[i] == ' ')
			continue;
		else {
			back_sen2 += all_sen[i];
		}
	}

	return 0;
}