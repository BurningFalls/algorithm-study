#include <iostream>
using namespace std;

int main() {
	int T;
	int arr1[6];
	int arr2[7];
	int sum1 = 0, sum2 = 0;
	cin >> T;
	for (int a = 0; a < T; a++) {
		for (int i = 0; i < 6; i++)
			cin >> arr1[i];
		sum1 = arr1[0] * 1 + arr1[1] * 2 + arr1[2] * 3 + arr1[3] * 3 + arr1[4] * 4 + arr1[5] * 10;
		for (int i = 0; i < 7; i++)
			cin >> arr2[i];
		sum2 = arr2[0] * 1 + arr2[1] * 2 + arr2[2] * 2 + arr2[3] * 2 + arr2[4] * 3 + arr2[5] * 5 + arr2[6] * 10;
		cout << "Battle " << a + 1 << ": ";
		if (sum1 > sum2)
			cout << "Good triumphs over Evil\n";
		else if (sum1 < sum2)
			cout << "Evil eradicates all trace of Good\n";
		else if (sum1 == sum2)
			cout << "No victor on this battle field\n";
	}

	return 0;
}