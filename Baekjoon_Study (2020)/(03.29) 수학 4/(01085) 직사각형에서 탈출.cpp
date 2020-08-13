#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int x, y, w, h;
	int minimum;
	int arr[4];
	cin >> x >> y >> w >> h;
	arr[0] = h - y;
	arr[1] = y;
	arr[2] = w - x;
	arr[3] = x;
	minimum = *min_element(arr, arr + 4);
	cout << minimum << endl;

	return 0;
}