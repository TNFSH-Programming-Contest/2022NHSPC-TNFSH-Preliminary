/**
 * By xiplus
 * 帳篷不能8方位相鄰
 * DSF每個位置決定是否放帳篷
 * 錯誤作法
 */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
const int WALL = 1;
const int TREE = 2;
const int TENT = 4;
#define endl '\n'

int v[MAXN][MAXN];
int n, m;
int rcnt[MAXN];
int ccnt[MAXN];
int cur_r[MAXN];
int cur_c[MAXN];
vector<pair<int, int>> dir8;

bool found = false;

void dfs(int r, int c) {
	if (found) {
		return;
	}

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
					if (v[q][w] & TREE) {
						cout << 'T';
					} else if (v[q][w] & TENT) {
						cout << 'A';
					} else {
						cout << '.';
					}
				}
				cout << endl;
			}
		}
		return;
	}

	// Put
	if (!v[r][c] && cur_r[r] < rcnt[r] && cur_c[c] < ccnt[c]) {
		bool conflict = false;
		for (int q = 0; q < 8; q++) {
			if (v[r + dir8[q].first][c + dir8[q].second] & TENT) {
				conflict = true;
				break;
			}
		}
		if (!conflict) {
			v[r][c] |= TENT;
			cur_r[r]++;
			cur_c[c]++;
			if (c == m) {
				if (cur_r[r] == rcnt[r]) {
					dfs(r + 1, 1);
				}
			} else {
				dfs(r, c + 1);
			}
			v[r][c] &= ~TENT;
			cur_r[r]--;
			cur_c[c]--;
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
	for (int q = -1; q <= 1; q++) {
		for (int w = -1; w <= 1; w++) {
			if (q == 0 && w == 0) {
				continue;
			}
			dir8.push_back({q, w});
		}
	}

	cin >> n >> m;
	for (int q = 1; q <= n; q++) {
		cin >> rcnt[q];
		v[q][0] |= WALL;
		v[q][m + 1] |= WALL;
	}
	for (int q = 1; q <= m; q++) {
		cin >> ccnt[q];
		v[0][q] |= WALL;
		v[n + 1][q] |= WALL;
	}
	char c;
	for (int q = 1; q <= n; q++) {
		for (int w = 1; w <= m; w++) {
			cin >> c;
			if (c == '.') {
				// pass
			} else if (c == 'T') {
				v[q][w] |= TREE;
			} else {
				return 1;
			}
		}
	}
	for (int q = 1; q <= n; q++) {
		for (int w = 1; w <= m; w++) {
			if (!v[q][w]) {
				if (v[q - 1][w] & TREE || v[q + 1][w] & TREE || v[q][w - 1] & TREE || v[q][w + 1] & TREE) {
					// pass
				} else {
					v[q][w] |= WALL;
				}
			}
		}
	}

	dfs(1, 1);
	if (!found) {
		cout << "QwQ" << endl;
	}

	return 0;
}
