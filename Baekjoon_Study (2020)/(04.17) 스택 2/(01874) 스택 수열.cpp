#include <iostream>
#include <vector>
using namespace std;

int arr[100001];

int main() {
	cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int N;
	vector<char> oper_v;
	vector<int> num_v;
	int node = 1;
	bool flag = true;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		if (!num_v.empty()) {
			if (arr[i] == num_v.back()) {
				num_v.pop_back();
				oper_v.push_back('-');
				continue;
			}
			else if (arr[i] < num_v.back()) {
				flag = false;
				break;
			}
		}
		for (int j = node; j <= arr[i]; j++) {
			num_v.push_back(j);
			oper_v.push_back('+');
		}
		node = arr[i] + 1;
		num_v.pop_back();
		oper_v.push_back('-');
	}

	if (flag) {
		for (int i = 0; i < oper_v.size(); i++) {
			cout << oper_v[i] << "\n";
		}
	}
	else {
		cout << "NO";
	}

	return 0;
}