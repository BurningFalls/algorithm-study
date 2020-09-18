#include <iostream>
using namespace std;

int main() {
	int N, M;
	char arr[101][101];
	char X;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[j][M - i - 1] == '.')
				cout << ".";
			else if (arr[j][M - i - 1] == 'O')
				cout << "O";
			else if (arr[j][M - i - 1] == '-')
				cout << "|";
			else if (arr[j][M - i - 1] == '|')
				cout << "-";
			else if (arr[j][M - i - 1] == '/')
				cout << "\\";
			else if (arr[j][M - i - 1] == '\\')
				cout << "/";
			else if (arr[j][M - i - 1] == '^')
				cout << "<";
			else if (arr[j][M - i - 1] == '<')
				cout << "v";
			else if (arr[j][M - i - 1] == 'v')
				cout << ">";
			else if (arr[j][M - i - 1] == '>')
				cout << "^";
		}
		cout << endl;
	}

	return 0;
}