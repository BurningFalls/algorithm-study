#include <iostream>
using namespace std;

int main() {
	int T;
	int Y_cnt;
	int K_cnt;
	int Y, K;
	cin >> T;
	for (int a = 0; a < T; a++) {
		Y_cnt = 0;
		K_cnt = 0;
		for (int i = 0; i < 9; i++) {
			cin >> Y >> K;
			Y_cnt += Y;
			K_cnt += K;
		}
		if (Y_cnt > K_cnt)
			cout << "Yonsei\n";
		else if (Y_cnt < K_cnt)
			cout << "Korea\n";
		else
			cout << "Draw\n";
	}


	return 0;
}