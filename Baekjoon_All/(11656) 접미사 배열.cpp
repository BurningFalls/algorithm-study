#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string sub_S[1001];

int main() {
	string S;
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		sub_S[i] = S.substr(i);
	}
	sort(sub_S, sub_S + S.size());
	for (int i = 0; i < S.size(); i++) {
		cout << sub_S[i] << "\n";
	}

	return 0;
}