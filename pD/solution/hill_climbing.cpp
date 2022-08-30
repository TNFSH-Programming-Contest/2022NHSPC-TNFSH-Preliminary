// By xiplus
// Hill climbing https://en.wikipedia.org/wiki/Hill_climbing

#include <bits/stdc++.h>
using namespace std;
#define MAXN 22
const int LAND = 1;
const int WALL = 2;	 // wall or not-connected tree
const int USED = 4;	 // connected to tent
const int TREE = 8;
const int TENT = 16;
const int BANNED = WALL | USED | TREE | TENT;
#define endl '\n'

int v[MAXN][MAXN];
int tv[MAXN][MAXN];
int n, m;
int tar_rcnt[MAXN];
int tar_ccnt[MAXN];
int rem_rcnt[MAXN];

struct Board {
	int used[MAXN][MAXN];
	int unused[MAXN][MAXN];
	int ccnt[MAXN];
};

const int next_cnt = 20;

Board cur_board;
Board next_board[next_cnt];

vector<int> aval_cidx[MAXN];

bool found = false;

mt19937 mt(time(nullptr));

void restart() {
	for (int w = 1; w <= m; w++) {
		cur_board.ccnt[w] = 0;
	}
	for (int q = 1; q <= n; q++) {
		shuffle(aval_cidx[q].begin(), aval_cidx[q].end(), mt);
		for (int w = 0; w < tar_rcnt[q]; w++) {
			cur_board.used[q][w] = aval_cidx[q][w];
			cur_board.ccnt[aval_cidx[q][w]]++;
		}
		for (int w = 0; w < rem_rcnt[q]; w++) {
			cur_board.unused[q][w] = aval_cidx[q][w + tar_rcnt[q]];
		}
	}
}

int calc_conflict(Board &board) {
	int res = 0;
	for (int w = 1; w <= m; w++) {
		res += abs(tar_ccnt[w] - board.ccnt[w]);
	}
	for (int q = 1; q < n; q++) {
		for (int w1 = 0; w1 < tar_rcnt[q]; w1++) {
			for (int w2 = 0; w2 < tar_rcnt[q + 1]; w2++) {
				if (board.used[q][w1] == board.used[q + 1][w2]) {
					res += 1;
				}
			}
		}
	}
	return res;
};

void show_board(Board &board) {
	memcpy(tv, v, sizeof(int) * MAXN * MAXN);
	for (int q = 1; q <= n; q++) {
		for (int w = 0; w < tar_rcnt[q]; w++) {
			tv[q][board.used[q][w]] |= TENT;
		}
		for (int w = 1; w <= m; w++) {
			if (tv[q][w] & TENT) {
				cout << 'A';
			} else if (tv[q][w] & TREE) {
				cout << 'T';
			} else {
				cout << '.';
			}
		}
		cout << endl;
	}
}

void search() {
	restart();
	int prev_conflict = calc_conflict(cur_board), min_conflict, conflict, pick_r, pick_c1, pick_c2;

	int step = 0, restart_cnt = 0;
	vector<int> best_idx;
	while (prev_conflict > 0 && step < 10000) {
		step++;
		best_idx.clear();
		min_conflict = 99999;
		for (int i = 0; i < next_cnt; i++) {
			memcpy(&next_board[i], &cur_board, sizeof(cur_board));
			do {
				pick_r = mt() % n + 1;
			} while (tar_rcnt[pick_r] == 0 || rem_rcnt[pick_r] == 0);
			pick_c1 = mt() % tar_rcnt[pick_r] + 1;
			pick_c2 = mt() % rem_rcnt[pick_r] + 1;

			swap(next_board[i].used[pick_r][pick_c1], next_board[i].used[pick_r][pick_c2]);

			conflict = calc_conflict(next_board[i]);
			if (conflict < min_conflict) {
				best_idx.clear();
				best_idx.push_back(i);
				min_conflict = conflict;
			} else if (conflict == min_conflict) {
				best_idx.push_back(i);
			}
		}
		if (min_conflict < prev_conflict) {
			pick_r = mt() % best_idx.size();
			memcpy(&cur_board, &next_board[pick_r], sizeof(cur_board));
			prev_conflict = min_conflict;
		} else {
			restart();
			restart_cnt += 1;
			prev_conflict = calc_conflict(cur_board);
		}
	}
	if (prev_conflict == 0) {
		show_board(cur_board);
	} else {
		cout << "QwQ" << endl;
	}
}

int main() {
	cin >> n >> m;
	for (int q = 1; q <= n; q++) {
		cin >> tar_rcnt[q];
		v[q][0] |= WALL;
		v[q][m + 1] |= WALL;
	}
	for (int q = 1; q <= m; q++) {
		cin >> tar_ccnt[q];
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
					aval_cidx[q].push_back(w);
				} else {
					v[q][w] |= WALL;
				}
			}
		}
		rem_rcnt[q] = aval_cidx[q].size() - tar_rcnt[q];
		if (rem_rcnt[q] < 0) {
			cout << "QwQ" << endl;
			return 0;
		}
	}

	search();

	return 0;
}
