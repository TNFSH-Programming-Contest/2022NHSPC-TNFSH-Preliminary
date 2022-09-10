#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
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

const int N = 2e5+10, MOD1 = 1e9+7, MOD2 = 1e8+7;

int n, m, s, t, q;

vector<int> G[N]; // {eid}
vector<pii> edg; // weight, to

int dis[N], sto[N];
void dijks() // s to t
{
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dis[s] = 0;
	sto[s] = 1;
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
				sto[v] = sto[u];
				dis[v] = d+w;
				pq.push({dis[v], v});
			}
			else if (dis[v] == d+w)
			{
				sto[v] = (sto[v] + sto[u])%MOD1;
			}
		}
	}
}

int tot[N];
int f(int u)
{
	if (tot[u] < 0)
	{
		if (u == t) tot[u] = 1;
		else
		{
			tot[u] = 0;
			for (auto e: G[u])
			{
				int w = edg[e].ff;
				int v = edg[e].ss;
				if (dis[v] != dis[u]+w) continue;
				tot[u] = (tot[u] + f(v))%MOD1;
			}
		}
	}
	return tot[u];
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

	dijks(); // build s-t dag and sto

	memset(tot, -1, sizeof(tot));

	cin >> q;
	while (q--)
	{
		int x, u, v, w;
		cin >> x;
		u = edg[(x-1)*2].ss;
		v = edg[(x-1)*2+1].ss;
		w = edg[(x-1)*2].ff;
		if (dis[u] > dis[v])
			swap(u, v);

//		de(u), de(v), de(x), de(sto[u]), de(f(v)), dd

		if (dis[u] + w != dis[v])
			cout << "no\n";
		else if (sto[u]*f(v)%MOD1 == sto[t])
			cout << "yes\n";
		else
			cout << "no\n";
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