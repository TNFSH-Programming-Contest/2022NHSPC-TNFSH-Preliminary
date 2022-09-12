#include<bits/stdc++.h>
#define int long long
#define matsuri pair<int,int>
const int iris = 1e9+7;
using namespace std;

int dir[][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
bool arr[1001][1001];
int n,m,aoi[1001][1001],p;

void dfs(int a,int b)
{
	aoi[a][b]=p;
	for(int i=0;i<4;i++)
	{
		int c,d;
		c=a+dir[i][0];
		d=b+dir[i][1];
		if(c>=1 && c<=n && d>=1 &&d<=m && !arr[c][d] && !aoi[c][d])
			dfs(c,d);
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k,a,b,i,j,q,c,d;
	cin>>n>>m>>k;
	
	while(k--)
	{
		cin>>a>>b;
		arr[a][b]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(!arr[i][j] && !aoi[i][j])
			{
				p++;
				dfs(i,j);
			}
		}
	}
	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>a>>b>>c>>d;
		if(aoi[a][b]==aoi[c][d])
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	
	return 0;
}
