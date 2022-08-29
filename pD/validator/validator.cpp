// By xiplus
#include "testlib.h"
using namespace std;

const int MAXN = 1000;

int main() {
	registerValidation();
	// about testlib, see https://codeforces.com/blog/entry/18291

	int n, m;
	n = inf.readInt();
	inf.readSpace();
	m = inf.readInt();
	inf.readEoln();

	for (int q = 0; q < n; q++) {
		if (q > 0) {
			inf.readSpace();
		}
		inf.readInt(0, m);
	}
	inf.readEoln();

	for (int q = 0; q < m; q++) {
		if (q > 0) {
			inf.readSpace();
		}
		inf.readInt(0, n);
	}
	inf.readEoln();

	char c;
	for (int q = 0; q < n; q++) {
		for (int w = 0; w < m; w++) {
			c = inf.readChar();
			ensuref(c == '.' || c == 'T', "except '.' or 'T', got %c.", c);
		}
		inf.readEoln();
	}

	inf.readEof();

	return 0;
}
