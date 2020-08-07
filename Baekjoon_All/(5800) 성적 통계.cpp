#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	int K;
	int N;
	int score[51];
	int max_dif;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> N;
		max_dif = 0;
		for (int j = 0; j < N; j++) {
			cin >> score[j];
		}
		cout << "Class " << i + 1 << endl;
		sort(score, score + N);
		for (int j = 0; j < N - 1; j++) {
			max_dif = max(max_dif, abs(score[j] - score[j + 1]));
		}
		cout << "Max " << score[N - 1] << ", Min " << score[0] << ", Largest gap " << max_dif << endl;
	}

	return 0;
}