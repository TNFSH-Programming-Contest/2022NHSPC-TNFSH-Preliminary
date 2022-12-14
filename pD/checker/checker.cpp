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

	int rcnt[n + 1], ccnt[m + 1];
	for (int q = 1; q <= n; q++) {
		if (q > 1) {
			inf.readSpace();
		}
		rcnt[q] = inf.readInt();
	}
	inf.readEoln();

	for (int q = 1; q <= m; q++) {
		if (q > 1) {
			inf.readSpace();
		}
		ccnt[q] = inf.readInt();
	}
	inf.readEoln();

	char itable[n + 1][m + 1];
	for (int q = 1; q <= n; q++) {
		for (int w = 1; w <= m; w++) {
			itable[q][w] = inf.readChar();
		}
		inf.readEoln();
	}

	string jans = ans.readString();

	vector<pair<int, int>> dir8;
	for (int q = -1; q <= 1; q++) {
		for (int w = -1; w <= 1; w++) {
			if (q == 0 && w == 0) {
				continue;
			}
			dir8.push_back({q, w});
		}
	}
	pair<int, int> dir4[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

	char ptable[n + 1][m + 1] = {};
	int prcnt[n + 1] = {}, pccnt[m + 1] = {}, tr, tc;
	set<pair<int, int>> tents;
	string s;
	for (int q = 1; q <= n; q++) {
		s = ouf.readString();
		if (s == "QwQ") {
			if (jans == "QwQ") {
				quitf(_ok, "The answer is correct.");
			} else {
				quitf(_wa, "The answer is not QwQ.");
			}
		}

		for (int w = 1; w <= m; w++) {
			ptable[q][w] = s[w - 1];

			if (itable[q][w] == 'T') {
				if (ptable[q][w] != 'T') {
					quitf(_wa, "(%d, %d) must be 'T', got '%c'.", q, w, ptable[q][w]);
				}
			} else {
				if (ptable[q][w] != '.' && ptable[q][w] != 'A') {
					quitf(_wa, "(%d, %d) must be '.' or 'A', got '%c'.", q, w, ptable[q][w]);
				}
			}

			if (ptable[q][w] == 'A') {
				tents.insert({q, w});
				prcnt[q]++;
				pccnt[w]++;
				if (q > 1 && itable[q - 1][w] == 'T') {
					// ok
				} else if (q < n && itable[q + 1][w] == 'T') {
					// ok
				} else if (w > 1 && itable[q][w - 1] == 'T') {
					// ok
				} else if (w < m && itable[q][w + 1] == 'T') {
					// ok
				} else {
					quitf(_wa, "Tent (%d, %d) not connected to Tree.", q, w);
				}

				for (int e = 0; e < 8; e++) {
					tr = q + dir8[e].first;
					tc = w + dir8[e].second;
					if (tr >= 1 && tr <= n && tc >= 1 && tc <= m && ptable[tr][tc] == 'A') {
						quitf(_wa, "Tent (%d, %d) is close to tent (%d, %d).", q + 1, w + 1, tr + 1, tc + 1);
					}
				}
			}
		}
	}
	for (int q = 1; q <= n; q++) {
		if (rcnt[q] != prcnt[q]) {
			quitf(_wa, "Count of tents on row %d incorrect.", q + 1);
		}
	}
	int remtent = 0;
	for (int q = 1; q <= m; q++) {
		if (ccnt[q] != pccnt[q]) {
			quitf(_wa, "Count of tents on col %d incorrect.", q + 1);
		}
		remtent += ccnt[q];
	}
	bool changed;
	int pr = 0, pc = 0, cont;

	bool solveCircle = false;
	while (remtent > 0) {
		changed = false;
		for (auto it = tents.begin(); it != tents.end();) {
			cont = 0;
			for (int q = 0; q < 4; q++) {
				tr = it->first + dir4[q].first;
				tc = it->second + dir4[q].second;
				if (tr >= 1 && tr <= n && tc >= 1 && tc <= m && ptable[tr][tc] == 'T') {
					pr = tr;
					pc = tc;
					cont++;
				}
			}
			if (cont == 1 || (cont > 1 && solveCircle)) {
				ptable[pr][pc] = '.';
				it = tents.erase(it);
				remtent--;
				changed = true;
				solveCircle = false;
			} else {
				it++;
			}
		}
		if (!changed) {
			if (!solveCircle) {
				solveCircle = true;
			} else {
				quitf(_wa, "Tent (%d, %d) connected to occupied tree", (*(tents.begin())).first, (*(tents.begin())).second);
			}
		}
	}

	if (jans == "QwQ") {
		quitf(_fail, "jury's answer is incorrect.");
	}

	quitf(_ok, "The answer is correct.");
}
