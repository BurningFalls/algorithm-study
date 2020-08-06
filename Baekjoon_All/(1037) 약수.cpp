#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	int* arr = new int[T];
	int maximum, minimum;
	for (int i = 0; i < T; i++) {
		cin >> arr[i];
	}
	maximum = *max_element(arr, arr + T);
	minimum = *min_element(arr, arr + T);
	cout << maximum * minimum << endl;
	return 0;
}