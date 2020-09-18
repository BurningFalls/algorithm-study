#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	string s1, s2;
	int arr[4] = { 0, };
	cin >> N;
	for (int a = 0; a < N; a++) {
		cin >> s1 >> s2;
		arr[0] = 0, arr[1] = 0, arr[2] = 0, arr[3] = 0;
		cout << s1 << ": ";
		for (int i = 0; i < s2.size(); i++) {
			if (s2[i] == 'B')
				arr[0]++;
			else if (s2[i] == 'C')
				arr[1]++;
			else if (s2[i] == 'M')
				arr[2]++;
			else if (s2[i] == 'W')
				arr[3]++;
		}
		arr[0] *= 2;
		arr[2] *= 4;
		arr[3] *= 3;
		if (arr[0] > arr[1] && arr[0] > arr[2] && arr[0] > arr[3])
			cout << "The Bobcat is the dominant species\n";
		else if (arr[1] > arr[0] && arr[1] > arr[2] && arr[1] > arr[3])
			cout << "The Coyote is the dominant species\n";
		else if (arr[2] > arr[0] && arr[2] > arr[1] && arr[2] > arr[3])
			cout << "The Mountain Lion is the dominant species\n";
		else if (arr[3] > arr[0] && arr[3] > arr[1] && arr[3] > arr[2])
			cout << "The Wolf is the dominant species\n";
		else
			cout << "There is no dominant species\n";
	}

	return 0;
}