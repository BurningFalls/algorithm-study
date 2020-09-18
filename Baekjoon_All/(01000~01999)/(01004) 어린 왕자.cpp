#include <iostream>
#include <utility>
#include <math.h>
using namespace std;

int main() {
	int T;
	int N;
	int x, y, z, w;
	pair<int, int> start;
	pair<int, int> end;
	int arr[51][3];
	double dif_fs, dif_fe;
	int cnt;
	cin >> T;
	for (int a = 0; a < T; a++) {
		cnt = 0;
		cin >> x >> y >> z >> w;
		start = make_pair(x, y);
		end = make_pair(z, w);
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			dif_fs = sqrt(pow(start.first - arr[i][0], 2) + pow(start.second - arr[i][1], 2));
			dif_fe = sqrt(pow(end.first - arr[i][0], 2) + pow(end.second - arr[i][1], 2));
			if ((dif_fs < arr[i][2] && dif_fe > arr[i][2]) || (dif_fs > arr[i][2] && dif_fe < arr[i][2])) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}