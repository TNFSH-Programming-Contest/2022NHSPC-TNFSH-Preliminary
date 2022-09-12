#include "testlib.h"
#include <iostream>
#include <set>
#include <vector>
#include <utility>
#define int long long
#define rep(i,j,k) for (int i=j; i<=k; i++)
#define de(x) cout << #x << "=" << x << ", "
#define dd cout << '\n';
#define ff first
#define ss second
#define pb push_back
#define lyx ios::sync_with_stdio(0), cin.tie(0);
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;

int mxN;
int mxM;
int mxQ;
int mxW;
int isTree;
int isChain;

const int N = 2e5+10;

int n, m, s, t;
set<int> G[N]; // to, w
vector<pair<pii, int>> edg;

int q;
vector<int> queries;

signed main(signed argc, char* argv[]) {
	registerGen(argc, argv, 1);
	mxN = atoll(argv[1]);
	mxM = atoll(argv[2]);
	mxQ = atoll(argv[3]);
	mxW = atoll(argv[4]);
	isTree = atoll(argv[5]);
    isChain = atoll(argv[6]);

    isTree |= isChain;
	n = rnd.wnext(1LL, mxN, 3);
	if (isTree) m = n-1;
	else m = rnd.wnext(n-1, min(n*(n-1)/2, mxM), 5);
	s = rnd.next(1LL, n);
	do
	{
		t = rnd.next(1LL, n);
	} while (t == s);

    if (isChain)
    {
        vector<int> nodes;
        rep(i,1,n) nodes.pb(i);
        shuffle(nodes.begin(), nodes.end());
        rep(i,1,nodes.size()-1)
        {
            int w = rnd.next(1LL, mxW);
            G[nodes[i-1]].insert(nodes[i]);
            edg.pb({{nodes[i-1], nodes[i]}, w});
        }
    }
    else
    {
        // gen tree
        rep(i,2,n)
        {
            int u = rnd.next(1LL, i-1);
            int w = rnd.next(1LL, mxW);
            G[u].insert(i);
            edg.pb({{u, i}, w});
        }
    }
	// randomly add edge
	while (edg.size() < m)
	{
		int u = rnd.next(1LL, n);
		int v = rnd.next(1LL, n);
		int w = rnd.next(1LL, mxW);
		if (u > v) swap(u, v);
		if (u == v) continue;
		if (G[u].find(v) != G[u].end()) continue;
		G[u].insert(v);
		edg.pb({{u, v}, w});
	}

	q = rnd.wnext(1LL, min(mxQ, m), 6);
	rep(i,1,m) queries.pb(i);
	shuffle(queries.begin(), queries.end());
	
	cout << n << ' ' << m << ' ' << s << ' ' << t << endl;
	shuffle(edg.begin(), edg.end());
	for (auto e: edg)
	{
		if (rnd.next(0,1))
			cout << e.ff.ff << ' ' << e.ff.ss << ' ' << e.ss << endl;
		else
			cout << e.ff.ss << ' ' << e.ff.ff << ' ' << e.ss << endl;
	}
	cout << q << endl;
	for (int i=0; i<q; i++) cout << queries[i] << endl;

}
