#include <iostream>
#include <string>


using namespace std;



void testX(string &S, int k) {
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == '-') {
			S[i] = NULL;
		}
	}
	string r = "";
	for (int i = 0; i < S.length(); i++) {
		if (S[i] != NULL) {
			r += S[i];
		}
	}
	string change = "";
	for (int i = 0; i < S.length(); i++) {
		if (i % k == 0 && i >= k) {
			change += '-';
		}
		else {
			change += r[i];
		}
	}

	S = change;
}
//The main method takes test cases from test0 through 3
int main() {
	string reg = "2-4A0r7-4k";

	testX(reg, 3);
	cout << reg << endl;
	cin.get();
}