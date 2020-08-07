#include <iostream>
#include <vector>
using namespace std;

int main() {
	int Z; // 테스트 케이스
	int n; // 호수의 개수
	int m; // 호수에 비가 내리는 날의 수
	int zero_count = 0; // 연속되는 0의 개수
	int num_count = 0; // 연속되는 자연수의 개수
	bool zero_flag = false; // 0을 지나쳤는지
	bool num_flag = false; // 자연수를 지나쳤는지
	vector<int> v; // 연속된 자연수를 담아놓는 벡터
	vector<int> ans; // YES인 경우 답을 담아놓는 벡터
	bool no_flag = false; // no가 되었는지

	cin >> Z;
	for (int a = 0; a < Z; a++) {
		ans.clear();
		v.clear();
		zero_flag = false;
		num_flag = false;
		no_flag = false;
		zero_count = 0;
		num_count = 0;

		cin >> n >> m;
		int* is_rain = new int[m]; // 0이면 비 안옴
		for (int i = 0; i < m; i++) {
			cin >> is_rain[i];
		}
		for (int i = 0; i < m; i++) {
			if (is_rain[i] == 0 && num_flag == false) {
				zero_flag = true;
				zero_count++;
			}
			else if (is_rain[i] == 0 && num_flag == true) {
				if (zero_count < num_count) {
					cout << "NO" << endl;
					no_flag = true;
					break;
				}
				for (int j = 0; j < v.size() - 1; j++) {
					for (int k = j + 1; k < v.size(); k++) {
						if (v[j] == v[k]) {
							cout << "NO" << endl;
							no_flag = true;
							k = v.size();
							j = v.size() - 1;
						}
					}
				}
				if (no_flag == true) {
					break;
				}
				for (int j = 0; j < v.size(); j++) {
					ans.push_back(v[j]);
				}
				for (int j = 0; j < zero_count - v.size(); j++) {
					ans.push_back(0);
				}
				v.clear();
				zero_flag = true;
				num_flag = false;
				zero_count = 1;
				num_count = 0;
			}
			else if (is_rain[i] != 0 && zero_flag == false) {
				cout << "NO" << endl;
				no_flag = true;
				break;
			}
			else if (is_rain[i] != 0 && zero_flag == true) {
				num_flag = true;
				num_count++;
				v.push_back(is_rain[i]);
			}
			if (no_flag == true) {
				break;
			}
		}
		if (v.size() == 0 && no_flag == false) {
			cout << "YES" << endl;
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i] << " ";
			}
			for (int i = 0; i < zero_count; i++) {
				cout << "0 ";
			}
			cout << endl;
		}
		else {
			if (no_flag == false) {
				if (zero_count < num_count) {
					cout << "NO" << endl;
					no_flag = true;
				}
				else {
					for (int j = 0; j < v.size() - 1; j++) {
						for (int k = j + 1; k < v.size(); k++) {
							if (v[j] == v[k]) {
								cout << "NO" << endl;
								no_flag = true;
								k = v.size();
								j = v.size() - 1;
							}
						}
					}
					if (no_flag == false) {
						for (int j = 0; j < v.size(); j++) {
							ans.push_back(v[j]);
						}
						for (int j = 0; j < zero_count - v.size(); j++) {
							ans.push_back(0);
						}
					}
				}
			}
			if (no_flag == false) {
				cout << "YES" << endl;
				for (int i = 0; i < ans.size(); i++) {
					cout << ans[i] << " ";
				}
				cout << endl;
			}
		}
	}


	return 0;
}