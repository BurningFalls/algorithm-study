#include <iostream>
#include <vector>
using namespace std;

vector<int> trinum;

bool Check(int num) {
	int len = trinum.size();
	int node = len;
	for (int i = 0; i < len; i++) {
		if (trinum[i] > num) {
			node = i;
			break;
		}
	}
	for (int i = 0; i < node; i++) {
		for (int j = 0; j < node; j++) {
			for (int k = 0; k < node; k++) {
				if (trinum[i] + trinum[j] + trinum[k] == num)
					return true;
			}
		}
	}
	return false;
}

int main() {
	int T;
	int K;

	for (int i = 1; i * (i + 1) / 2 <= 1000; i++) {
		trinum.push_back(i * (i + 1) / 2);
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> K;
		if (Check(K))
			cout << "1\n";
		else
			cout << "0\n";
	}


	return 0;
}