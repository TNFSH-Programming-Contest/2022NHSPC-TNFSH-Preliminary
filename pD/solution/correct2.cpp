// By xiplus
#include <bits/stdc++.h>
using namespace std;
#define MAXN 15
#define EMPTY 0
#define BANNED 1
#define WALL 2
#define TREE 3
#define TENT 4
#define endl '\n'

int v[MAXN][MAXN];
int n, m;
int rcnt[MAXN];
int ccnt[MAXN];
int cur_r[MAXN];
int cur_c[MAXN];

char SIGN[] = {'.', '.', 'X', 'T', 'A'};
bool found = false;

void dfs(int r, int c) {
	if (found) {
		return;
	}

	// cout << "dfs " << r << " " << c << endl;
	if (r > n) {
		bool ok = true;
		for (int q = 1; q <= n; q++) {
			if (rcnt[q] != cur_r[q]) {
				ok = false;
				break;
			}
		}
		for (int q = 1; q <= m; q++) {
			if (ccnt[q] != cur_c[q]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			found = true;
			for (int q = 1; q <= n; q++) {
				for (int w = 1; w <= m; w++) {
					cout << SIGN[v[q][w]];
				}
				cout << endl;
			}
		}
		return;
	}

	// Put
	if (v[r][c] == EMPTY && cur_r[r] < rcnt[r] && cur_c[c] < ccnt[c]) {
		v[r][c] = TENT;
		cur_r[r]++;
		cur_c[c]++;
		if (v[r][c + 1] == EMPTY) {
			v[r][c + 1] = BANNED;
		}
		if (v[r + 1][c] == EMPTY) {
			v[r + 1][c] = BANNED;
		}
		if (c == m) {
			if (cur_r[r] == rcnt[r]) {
				dfs(r + 1, 1);
			}
		} else {
			dfs(r, c + 1);
		}
		v[r][c] = EMPTY;
		cur_r[r]--;
		cur_c[c]--;
		if (v[r][c + 1] == BANNED) {
			v[r][c + 1] = EMPTY;
		}
		if (v[r + 1][c] == BANNED) {
			v[r + 1][c] = EMPTY;
		}
	}
	// Not put
	if (c == m) {
		if (cur_r[r] == rcnt[r]) {
			dfs(r + 1, 1);
		}
	} else {
		dfs(r, c + 1);
	}
}

int main() {
	cin >> n >> m;
	for (int q = 1; q <= n; q++) {
		cin >> rcnt[q];
		v[q][0] = WALL;
		v[q][m + 1] = WALL;
	}
	for (int q = 1; q <= m; q++) {
		cin >> ccnt[q];
		v[0][q] = WALL;
		v[n + 1][q] = WALL;
	}
	char c;
	for (int q = 1; q <= n; q++) {
		for (int w = 1; w <= m; w++) {
			cin >> c;
			if (c == '.') {
				v[q][w] = EMPTY;
			} else if (c == 'T') {
				v[q][w] = TREE;
			} else {
				return 1;
			}
		}
	}
	for (int q = 1; q <= n; q++) {
		for (int w = 1; w <= m; w++) {
			if (v[q][w] == EMPTY) {
				if (v[q - 1][w] != TREE && v[q + 1][w] != TREE && v[q][w - 1] != TREE && v[q][w + 1] != TREE) {
					v[q][w] = BANNED;
				}
			}
		}
	}
	// for (int q = 0; q <= n + 1; q++) {
	// 	for (int w = 0; w <= m + 1; w++) {
	// 		cout << SIGN[v[q][w]];
	// 	}
	// 	cout << endl;
	// }

	dfs(1, 1);
	if (!found) {
		cout << "QwQ" << endl;
	}

	return 0;
}
