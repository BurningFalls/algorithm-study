#include <iostream>
#include <string>
using namespace std;

int main() {
	string H;
	string N;
	int total_cnt = 0;
	int sub_cnt = 0;
	cin >> H;
	cin >> N;
	for (int i = 0; i < H.size(); i++) {
		sub_cnt = 0;
		for (int j = 0; j < N.size(); j++) {
			if (H[i + j] != N[j]) {
				break;
			}
			else {
				sub_cnt++;
			}
		}
		if (sub_cnt == N.size()) {
			total_cnt++;
		}
	}
	cout << total_cnt;

	return 0;
}