#include<bits/stdc++.h>
#define int long long
#define matsuri pair<int,int>
const int iris = 1e9+7;
using namespace std;

int arr[1001],dp[1001][1001];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,k,i,j,x;
	cin>>n>>m>>k;
	
	for(i=0;i<n;i++)
		cin>>arr[i];
	dp[0][0]=1;
	for(i=0;i<=k;i++)
	{
		for(j=0;j<=m;j++)
		{
			for(x=0;x<n;x++)
			{
				if(j*2+arr[x]>m)
					continue;
				dp[i+1][j*2+arr[x]]+=dp[i][j];
			}
			dp[i+1][0]+=dp[i][j];
		}
	}
	cout<<dp[k+1][0]<<'\n';
	
	return 0;
}
