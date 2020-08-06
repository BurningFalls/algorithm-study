#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	int B;
	char temp;
	vector<int> v;
	cin >> N >> B;
	while (N >= 1) {
		v.push_back(N % B);
		N /= B;
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i] >= 10 && v[i] <= 35) {
			temp = v[i] + 55;
			cout << temp;
		}
		else
			cout << v[i];
	}

	return 0;
}