#include <iostream>
#include <string>
using namespace std;

int main() {
	int S;
	string str;
	int consonant, vowel;
	int len;
	cin >> S;
	cin.ignore();
	for (int i = 0; i < S; i++) {
		getline(cin, str);
		consonant = 0, vowel = 0;
		len = str.size();
		for (int j = 0; j < len; j++) {
			if (str[j] == 'a' || str[j] == 'e' || str[j] == 'i' || str[j] == 'o' || str[j] == 'u' ||
				str[j] == 'A' || str[j] == 'E' || str[j] == 'I' || str[j] == 'O' || str[j] == 'U') {
				vowel++;
			}
			else if (str[j] == ' ')
				continue;
			else
				consonant++;
		}
		cout << consonant << " " << vowel << "\n";
	}

	return 0;
}