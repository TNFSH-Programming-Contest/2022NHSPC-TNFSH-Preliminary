#include <bits/stdc++.h>
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

const int N = 1e5+10;

int n, m, s, t, q;

vector<int> G[N]; // {eid}
vector<pii> edg; // weight, to

int dis[N];
int dijks() // s to t
{
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dis[s] = 0;
	pq.push({0, s});

	while (!pq.empty())
	{
		int d = pq.top().ff;
		int u = pq.top().ss;
		pq.pop();

		if (dis[u] < d) continue;

		for (auto e: G[u])
		{
			int w = edg[e].ff;
			int v = edg[e].ss;
			if (dis[v]>d+w)
			{
				dis[v] = d+w;
				pq.push({dis[v], v});
			}
		}
	}
	return dis[t];
}

signed main()
{
	lyx
	cin >> n >> m >> s >> t;
	for (int i=1; i<=m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u].pb(edg.size());
		edg.pb({w, v});
		G[v].pb(edg.size());
		edg.pb({w, u});
	}

	int ori = dijks();

	cin >> q;
	while (q--)
	{
		int x, tmp;
		cin >> x;
		tmp = edg[(x-1)*2].ff;
		edg[(x-1)*2].ff = 1e18;
		edg[(x-1)*2+1].ff = 1e18;

		if (ori != dijks()) cout << "yes\n";
		else cout << "no\n";

		edg[(x-1)*2].ff = tmp;
		edg[(x-1)*2+1].ff = tmp;
	}
}
// 0, 1, 2, 3, 4, 5
// 1,    2,    3,   
// /2+1
// (x-1)*2, (x-1)*2+1

/*
4 5 1 4
1 3 1
1 2 2
3 2 1
3 4 3
2 4 1
5
1
2
3
4
5

*/