// By xiplus
// 帳篷不能8方位相鄰
// 帳篷:樹 = 1:1
#include <bits/stdc++.h>

#include "testlib.h"
using namespace std;

const int TENT = 1;
const int TREE = 2;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	// about testlib, see https://codeforces.com/blog/entry/18291

	int n1 = atoi(argv[1]);	 // n min
	int n2 = atoi(argv[2]);	 // n max
	int m1 = atoi(argv[3]);	 // m min
	int m2 = atoi(argv[4]);	 // m max
	int t1 = atoi(argv[5]);	 // tree min
	int t2 = atoi(argv[6]);	 // tree max

	int n = rnd.next(n1, n2);
	int m = rnd.next(m1, m2);

	cout << n << " " << m << endl;

	vector<pair<int, int>> dir4{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	vector<pair<int, int>> dir8;
	for (int q = -1; q <= 1; q++) {
		for (int w = -1; w <= 1; w++) {
			if (q == 0 && w == 0) {
				continue;
			}
			dir8.push_back({q, w});
		}
	}

	int G[n + 2][m + 2] = {};
	int banned[n + 2][m + 2] = {};
	vector<pair<int, int>> pos;
	for (int q = 1; q <= n; q++) {
		for (int w = 1; w <= m; w++) {
			pos.push_back({q, w});
		}
	}
	shuffle(pos.begin(), pos.end());

	int tcnt = rnd.next(t1, t2);
	int r, c, tr, tc;
	bool puttree;
	for (auto tpos : pos) {
		r = tpos.first;
		c = tpos.second;
		if (banned[r][c] == 0) {
			shuffle(dir4.begin(), dir4.end());
			puttree = false;
			for (int q = 0; q < 4; q++) {
				tr = r + dir4[q].first;
				tc = c + dir4[q].second;
				if (G[tr][tc] == 0 && tr >= 1 && tr <= n && tc >= 1 && tc <= m) {
					G[tr][tc] = TREE;
					puttree = true;
					break;
				}
			}
			if (puttree) {
				G[r][c] = TENT;
				for (auto dir : dir8) {
					banned[r + dir.first][c + dir.second] = 1;
				}
				tcnt--;
			}
		}
		if (tcnt == 0) {
			break;
		}
	}

	if (tcnt > 0) {
		cerr << "No place to put tents, remaining " << tcnt << endl;
	}

	int sum;

	for (int q = 1; q <= n; q++) {
		if (q > 1) {
			cout << " ";
		}
		sum = 0;
		for (int w = 1; w <= m; w++) {
			if (G[q][w] == TENT) {
				sum++;
			}
		}
		cout << sum;
	}
	cout << endl;

	for (int q = 1; q <= m; q++) {
		if (q > 1) {
			cout << " ";
		}
		sum = 0;
		for (int w = 1; w <= n; w++) {
			if (G[w][q] == TENT) {
				sum++;
			}
		}
		cout << sum;
	}
	cout << endl;

	for (int q = 1; q <= n; q++) {
		for (int w = 1; w <= m; w++) {
			if (G[q][w] == TREE) {
				cout << 'T';
			} else {
				cout << '.';
			}
		}
		cout << endl;
	}

	// answer to cerr
	cerr << endl;
	for (int q = 1; q <= n; q++) {
		for (int w = 1; w <= m; w++) {
			if (G[q][w] == TENT) {
				cerr << 'A';
			} else if (G[q][w] == TREE) {
				cerr << 'T';
			} else {
				cerr << '.';
			}
		}
		cerr << endl;
	}

	return 0;
}
