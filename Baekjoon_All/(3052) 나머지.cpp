#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> arr;
	int num;
	for (int i = 0; i < 10; i++) {
		cin >> num;
		arr.push_back(num % 42);
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	cout << arr.size() << endl;
}