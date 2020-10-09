#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define pii pair<int, int>
#define PQ priority_queue<int>

int main() {
	FASTIO;
	int N;
	int num;
	PQ max_heap, min_heap;
	cin >> N;
	FOR(i, 1, N) {
		cin >> num;
		if (i % 2 == 1)
			max_heap.push(num);
		else if (i % 2 == 0)
			min_heap.push(-num);
		if (!max_heap.empty() && !min_heap.empty()) {
			int maxh = max_heap.top();
			int minh = -min_heap.top();
			if (maxh > minh) {
				max_heap.pop();
				min_heap.pop();
				max_heap.push(minh);
				min_heap.push(-maxh);
			}
		}
		cout << max_heap.top() << "\n";
	}

	return 0;
}