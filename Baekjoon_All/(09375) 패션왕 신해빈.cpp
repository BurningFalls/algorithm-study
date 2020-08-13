#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int T;
	int N;
	vector<pair<string, string>> v;
	vector<pair<string, int>> same;
	string a, b;
	bool same_flag;
	int same_len;
	long long int mul_ans;

	cin >> T;
	for (int A = 0; A < T; A++) {
		mul_ans = 1;
		v.clear();
		same.clear();
		cin >> N;
		if (N == 0) {
			cout << 0 << "\n";
		}
		else {
			for (int i = 0; i < N; i++) {
				cin >> a >> b;
				v.push_back(make_pair(a, b));
			}
			same.push_back(make_pair(v[0].second, 1));
			for (int i = 1; i < N; i++) {
				same_flag = false;
				for (int j = 0; j < same.size(); j++) {
					if (same[j].first == v[i].second) {
						same[j].second++;
						same_flag = true;
						break;
					}
				}
				if (same_flag == false) {
					same.push_back(make_pair(v[i].second, 1));
				}
			}
			same_len = same.size();
			for (int i = 0; i < same_len; i++) {
				mul_ans *= (same[i].second + 1);
			}
			cout << mul_ans - 1 << "\n";
		}
	}


	return 0;
}