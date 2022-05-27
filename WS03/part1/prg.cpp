#include <iostream>
#include <string>
#include "Array.h"
#include "KVP.h"
using namespace sdds;
using namespace std;

int main() {
	Array<int> A(5);
	Array<string> S;
	Array<KVP<string, int, 2>> kvp;

	unsigned int i;
	/*for (i = 0; i < 7; i++) {
		A[i] = i * 2;
	}
	for (i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}

	cout << "Enter 3 names: " << endl;
	for (i = 0; i < 3; i++) {
		cout << (i + 1) << ": ";
		cin >> S[i];
	}

	for (i = 0; i < S.size(); i++) {
		cout << (i + 1) << ": " << S[i] << endl;
	}*/

	cout << "Enter 3 names and their lab and diy marks: " << endl;
	for (i = 0; i < 3; i++) {
		cout << (i + 1) << ": ";
		cin >> kvp[i];
	}

	for (i = 0; i < kvp.size(); i++) {
		cout << (i + 1) << ": " << kvp[i] << endl;
	}

	return 0;
}
