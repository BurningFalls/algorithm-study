#include <stdio.h>
using namespace std;

int main() {
	char c[] = { 0xEF, 0xBF, 0xBD, 0 };
	puts(c);
	return 0;
}