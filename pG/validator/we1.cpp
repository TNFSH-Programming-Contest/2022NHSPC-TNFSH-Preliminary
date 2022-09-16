// By xiplus
#include "testlib.h"
using namespace std;

int v[200005];
int deg[200005];

int find(int a) {
	if (v[a] == a) return a;
	return v[a] = find(v[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		v[b] = a;
	}
}

int main() {
	registerValidation();
	// about testlib, see https://codeforces.com/blog/entry/18426

	int n = inf.readInt(1, 500);
	inf.readSpace();
	int m = inf.readInt(1, 500);
	inf.readSpace();
	int s = inf.readInt(1, n);
	inf.readSpace();
	int t = inf.readInt(1, n);
	inf.readEoln();

	for (int i = 1; i <= n; i++) {
		v[i] = i;
	}

	ensure(s != t);

	for (int i = 0; i < m; i++) {
		int u = inf.readInt(1, n);
		inf.readSpace();
		int v = inf.readInt(1, n);
		inf.readSpace();
		int w = inf.readInt(1, 1, "w");
		inf.readEoln();

		merge(u, v);
	}

	for (int i = 2; i <= n; i++) {
		ensuref(find(1) == find(i), "1 and %d is not connected", i);
	}

	int q = inf.readInt(1, m);
	inf.readEoln();

	for (int i = 0; i < q; i++) {
		inf.readInt(1, m, "x");
		inf.readEoln();
	}

	inf.readEof();

	return 0;
}
