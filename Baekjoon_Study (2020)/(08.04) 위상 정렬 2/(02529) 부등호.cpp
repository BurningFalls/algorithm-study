#include <bits/stdc++.h>
using namespace std;

int N;
int K;
vector<int> v[10];
int cnt1[10] = { 0, };
int cnt2[10] = { 0, };
int ord1[10];
int ord2[10];

void TP1() {
	priority_queue<int, vector<int>, less<int>> pq1;
	for (int i = 0; i < N; i++) {
		if (cnt1[i] == 0) {
			pq1.push(i);
		}
	}
	for (int i = 0; i < N; i++) {
		int node = pq1.top();
		pq1.pop();
		ord1[i] = node;
		int len = v[node].size();
		for (int j = 0; j < len; j++) {
			int new_node = v[node][j];
			cnt1[new_node]--;
			if (cnt1[new_node] == 0)
				pq1.push(new_node);
		}
	}
}

void TP2() {
	priority_queue<int, vector<int>, greater<int>> pq2;
	for (int i = 0; i < N; i++) {
		if (cnt2[i] == 0) {
			pq2.push(i);
		}
	}
	for (int i = 0; i < N; i++) {
		int node = pq2.top();
		pq2.pop();
		ord2[i] = node;
		int len = v[node].size();
		for (int j = 0; j < len; j++) {
			int new_node = v[node][j];
			cnt2[new_node]--;
			if (cnt2[new_node] == 0)
				pq2.push(new_node);
		}
	}
}

int main() {
	char X;
	int ans1[10];
	cin >> K;
	N = K + 1;
	for (int i = 0; i < K; i++) {
		cin >> X;
		if (X == '<') {
			v[i].push_back(i + 1);
			cnt1[i + 1]++;
		}
		else if (X == '>') {
			v[i + 1].push_back(i);
			cnt1[i]++;
		}
	}
	for (int i = 0; i < N; i++)
		cnt2[i] = cnt1[i];
	TP1();
	TP2();
	for (int i = 0; i < N; i++) {
		ans1[ord1[i]] = 9 - K + i;
	}
	for (int i = 0; i < N; i++) {
		cout << ans1[i];
	}
	cout << "\n";
	for (int i = 0; i < N; i++) {
		cout << ord2[i];
	}


	return 0;
}