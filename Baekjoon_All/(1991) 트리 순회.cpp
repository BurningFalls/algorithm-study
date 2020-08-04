#include <iostream>
using namespace std;

pair<char, char> child[26];

void Func1(char node) {
	if (node == '.')
		return;
	cout << node;
	Func1(child[node - 'A'].first);
	Func1(child[node - 'A'].second);
}

void Func2(char node) {
	if (node == '.')
		return;
	Func2(child[node - 'A'].first);
	cout << node;
	Func2(child[node - 'A'].second);
}

void Func3(char node) {
	if (node == '.')
		return;
	Func3(child[node - 'A'].first);
	Func3(child[node - 'A'].second);
	cout << node;
}

int main() {
	int N;
	char X1, X2, X3;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X1 >> X2 >> X3;
		child[X1 - 'A'] = make_pair(X2, X3);
	}
	Func1('A');
	cout << "\n";
	Func2('A');
	cout << "\n";
	Func3('A');

	return 0;
}