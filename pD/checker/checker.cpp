#include <bits/stdc++.h>

#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerChecker("pD", argc, argv);
	// ref: https://codeforces.com/blog/entry/18431
	int n, m;
	n = inf.readInt();
	inf.readSpace();
	m = inf.readInt();
	inf.readEoln();

	int rcnt[n], ccnt[m];
	for (int q = 0; q < n; q++) {
		if (q > 0) {
			inf.readSpace();
		}
		rcnt[q] = inf.readInt();
	}
	inf.readEoln();

	for (int q = 0; q < m; q++) {
		if (q > 0) {
			inf.readSpace();
		}
		ccnt[q] = inf.readInt();
	}
	inf.readEoln();

	char itable[n][m];
	for (int q = 0; q < n; q++) {
		for (int w = 0; w < m; w++) {
			itable[q][w] = inf.readChar();
		}
		inf.readEoln();
	}

	string jans = ans.readString();

	char ptable[n][m];
	int prcnt[n] = {}, pccnt[m] = {};
	string s;
	for (int q = 0; q < n; q++) {
		s = ouf.readString();
		if (s == "QwQ") {
			if (jans == "QwQ") {
				quitf(_ok, "The answer is correct.");
			} else {
				quitf(_wa, "The answer is not QwQ.");
			}
		}

		for (int w = 0; w < m; w++) {
			ptable[q][w] = s[w];

			if (itable[q][w] == 'T') {
				if (ptable[q][w] != 'T') {
					quitf(_wa, "(%d, %d) must be 'T', got '%c'.", q + 1, w + 1, ptable[q][w]);
				}
			} else {
				if (ptable[q][w] != '.' && ptable[q][w] != 'A') {
					quitf(_wa, "(%d, %d) must be '.' or 'A', got '%c'.", q + 1, w + 1, ptable[q][w]);
				}
			}

			if (ptable[q][w] == 'A') {
				prcnt[q]++;
				pccnt[w]++;
				if (q > 0 && itable[q - 1][w] == 'T') {
					// ok
				} else if (q < n - 1 && itable[q + 1][w] == 'T') {
					// ok
				} else if (w > 0 && itable[q][w - 1] == 'T') {
					// ok
				} else if (w < m - 1 && itable[q][w + 1] == 'T') {
					// ok
				} else {
					quitf(_wa, "Tent (%d, %d) not connected to Tree.", q + 1, w + 1);
				}
			}
		}
	}
	for (int q = 0; q < n; q++) {
		if (rcnt[q] != prcnt[q]) {
			quitf(_wa, "Count of tents on row %s incorrect.", q + 1);
		}
	}
	for (int q = 0; q < m; q++) {
		if (ccnt[q] != pccnt[q]) {
			quitf(_wa, "Count of tents on col %s incorrect.", q + 1);
		}
	}

	if (jans == "QwQ") {
		quitf(_fail, "jury's answer is incorrect.");
	}

	quitf(_ok, "The answer is correct.");

	return 0;
}
