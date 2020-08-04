#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	getline(cin, S);
	int len = S.size();
	bool word_flag = false;
	int count = 0;

	for (int i = 0; i < len; i++) {
		// 띄어쓰기이고 이전에 단어가 있었다면
		// (단어 하나를 다 지나서 공백에 도달했다면)
		// 현재 상태를 false로 바꿈
		if (S[i] == ' ' && word_flag == true) {
			word_flag = false;
		}
		// 문자이고 이전에 단어가 없었다면
		// (띄어쓰기였다가 새로운 단어에 도달했다면)
		// 현재 상태를 true로 바꿈
		// 새로운 단어에 도달했으므로 count에 +1
		else if (S[i] != ' ' && word_flag == false) {
			word_flag = true;
			count++;
		}
		// if (S[i] == ' ' && word_flag == false)
		// -> 공백을 계속해서 읽어 나가므로 무의미
		// (S[i] != ' ' && word_flag == true) 
		// -> 문자를 계속해서 읽어 나가므로 무의미
	}
	cout << count << endl;

	return 0;
}