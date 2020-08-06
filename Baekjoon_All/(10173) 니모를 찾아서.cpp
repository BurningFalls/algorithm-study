#include <iostream>
#include <string>
using namespace std;

int main() {
	string nemo[16] = { "nemo", "Nemo", "nEmo", "neMo", "nemO",
	"NEmo", "NeMo", "NemO", "nEMo", "nEmO", "neMO", "NEMo",
	"NEmO", "NeMO", "nEMO", "NEMO" };
	string str;
	bool flag;
	while (true) {
		flag = false;
		getline(cin, str);
		if (str == "EOI")
			break;
		for (int i = 0; i < 16; i++) {
			if (str.find(nemo[i]) != string::npos) {
				flag = true;
				break;
			}
		}
		if (flag == true)
			cout << "Found\n";
		else
			cout << "Missing\n";
	}
	return 0;
}