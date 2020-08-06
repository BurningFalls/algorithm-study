#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	int P;
	int C;
	int max_C;
	string max_name;
	string name;
	cin >> N;
	for (int i = 0; i < N; i++) {
		max_C = 0;
		cin >> P;
		for (int j = 0; j < P; j++) {
			cin >> C >> name;
			if (max_C <= C) {
				max_C = C;
				max_name = name;
			}
		}
		cout << max_name << "\n";
	}

	return 0;
}