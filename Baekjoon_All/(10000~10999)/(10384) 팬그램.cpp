#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int arr[26] = { 0, };
	string str;
	int len;
	int maximum;
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		getline(cin, str);
		len = str.size();
		for (int j = 0; j < 26; j++)
			arr[j] = 0;
		for (int j = 0; j < len; j++) {
			if (str[j] >= int('A') && str[j] <= int('Z')) {
				arr[str[j] - 'A']++;
			}
			else if (str[j] >= int('a') && str[j] <= int('z')) {
				arr[str[j] - 'a']++;
			}
		}
		maximum = *min_element(arr, arr + 26);
		cout << "Case " << i + 1 << ": ";
		if (maximum == 0)
			cout << "Not a pangram\n";
		else if (maximum == 1)
			cout << "Pangram!\n";
		else if (maximum == 2)
			cout << "Double pangram!!\n";
		else if (maximum == 3)
			cout << "Triple pangram!!!\n";
	}

	return 0;
}