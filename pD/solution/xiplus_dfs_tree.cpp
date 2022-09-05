/**
 * By xiplus
 * 帳篷不能8方位相鄰
 * DFS每棵樹，嘗試4個方位
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
vector<pair<int, int>> trees;
pair<int, int> dir4[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<int, int>> dir8;

bool found = false, conflict;

void dfs(int treei) {
	if (found) {
		return;
	}
	if (treei >= (int)trees.size()) {
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
		return;
	}

	for (int d1 = 0; d1 < 4; d1++) {
		int tr = trees[treei].first + dir4[d1].first;
		int tc = trees[treei].second + dir4[d1].second;
		if (!v[tr][tc] && cur_r[tr] < rcnt[tr] && cur_c[tc] < ccnt[tc]) {
			conflict = false;
			for (int d2 = 0; d2 < 8; d2++) {
				if (v[tr + dir8[d2].first][tc + dir8[d2].second] & TENT) {
					conflict = true;
					break;
				}
			}
			if (!conflict) {
				v[tr][tc] |= TENT;
				cur_r[tr]++;
				cur_c[tc]++;

				dfs(treei + 1);

				v[tr][tc] &= ~TENT;
				cur_r[tr]--;
				cur_c[tc]--;
			}
		}
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
				trees.push_back({q, w});
			} else {
				return 1;
			}
		}
	}

	dfs(0);
	if (!found) {
		cout << "QwQ" << endl;
	}

	return 0;
}
