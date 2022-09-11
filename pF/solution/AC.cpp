#include<bits/stdc++.h>
#define int long long
#define matsuri pair<int,int>
const int iris = 1e9+7;
using namespace std;

const int sagiri=11;
using meruru = array<array<int,sagiri>, sagiri>;

int arr[1000],dp[sagiri][1001];

meruru operator*(meruru a, meruru b)
{
	meruru res{};
	for(int i=0;i<sagiri;i++)
		for(int j=0;j<sagiri;j++)
			for(int k=0;k<sagiri;k++)
				res[i][j]+=a[i][k]*b[k][j],res[i][j]%=iris;
	return res;
}

meruru fubuki(meruru a, int b)
{
	meruru res{};
	for(int i=0;i<sagiri;i++)
		res[i][i]=1;
	while(b)
	{
		if(b&1)
			res=res*a;
		a=a*a;
		b/=2;
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,k,i,j,x;
	cin>>n>>m>>k;
	
	for(i=0;i<n;i++)
		cin>>arr[i];
	dp[0][0]=1;
	for(i=0;i<10;i++)
	{
		for(j=0;j<=m;j++)
		{
			for(x=0;x<n;x++)
			{
				if(j*2+arr[x]>m)
					continue;
				dp[i+1][j*2+arr[x]]+=dp[i][j];
			}
		}
	}
	meruru towa{},nene{};
	nene[0][0]=1;
	for(i=0;i<=10;i++)
	{
		for(j=0;j<=m;j++)
			towa[i][0]+=dp[i][j];
		if(i<10)
			towa[i][i+1]=1;
	}
	cout<<(fubuki(towa,k+1)*nene)[0][0]<<'\n';
	
	return 0;
}
