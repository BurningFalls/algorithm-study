#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	int arr[26] = { 0, };
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		arr[int(S[i]) - 97]++;
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}