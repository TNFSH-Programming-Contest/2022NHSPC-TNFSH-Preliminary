#include "testlib.h"
#include <bits/stdc++.h>
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
using namespace std;

int mnN;
int mxN;
int mnM;
int mxM;
int treeRatio;
int tentRatio;

const int N = 20;
int n, m, rreq[N], creq[N];
char G[N][N];
int has_sol;

int can(int i, int j)
{
    if (G[i][j] == 'T')
        return 0;
    if (G[i+1][j]=='A'||G[i][j+1]=='A'||G[i-1][j]=='A'||G[i][j-1]=='A')
        return 0;
    if (G[i+1][j]!='T'&&G[i][j+1]!='T'&&G[i-1][j]!='T'&&G[i][j-1]!='T')
        return 0;
    return 1;
}

signed main(signed argc, char* argv[]) {
	registerGen(argc, argv, 1);
	mnN = atoll(argv[1]);
	mxN = atoll(argv[2]);
	mnM = atoll(argv[3]);
	mxM = atoll(argv[4]);
	treeRatio = atoll(argv[5]);
	tentRatio = atoll(argv[6]);

	n = rnd.wnext(mnN, mxN, 2);
	m = rnd.wnext(mnN, mxN, 2);
	has_sol = rnd.next(1,100) <= 80;

	rep(i,1,n) rep(j,1,m) G[i][j] = '.';

	rep(i,1,n)
		rep(j,1,m)
			if (rnd.next(1,100) <= treeRatio)
				G[i][j] = 'T';

	rep(i,1,n)
		rep(j,1,m)
			if (can(i,j) && rnd.next(1, 100) <= tentRatio)
				G[i][j] = 'A', rreq[i]++, creq[j]++;

	if (!has_sol)
	{
		rep(i,1,n) rreq[i] = rnd.wnext(1, m, 3);
		rep(i,1,m) creq[i] = rnd.wnext(1, n, 3);
	}
	
	cout << n << ' ' << m << '\n';
	rep(i,1,n) cout << rreq[i] << "\n "[i+1 <= n];
	rep(i,1,m) cout << creq[i] << "\n "[i+1 <= m];
	rep(i,1,n)
	{
		rep(j,1,m) cout << (G[i][j]=='T'? 'T':'.');
		cout << endl;
	}
	return 0;
}
