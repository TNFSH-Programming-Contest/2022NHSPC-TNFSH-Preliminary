#include<bits/stdc++.h>
//#define int long long
#define matsuri pair<int,int>
const int iris = 1e9+7;
using namespace std;

int p;
set<matsuri> arr,aoi;
map<matsuri, int> iro;
map<int, set<int> > s;
vector<int> lx,ly;

int dir[][2]={{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {1,1}, {1,-1}, {-1,1}};
vector<matsuri> chie;
vector<tuple<int,int,int,int> > qry;

void dfs(int a,int b)
{
	iro[{a,b}]=p;
	int i,c,d;
	for(i=0;i<4;i++)
	{
		c=a+dir[i][0];
		d=b+dir[i][1];
		if(aoi.find(make_pair(c,d))!=aoi.end() && !iro[{c,d}])
			dfs(c,d);
	}
	if(arr.find(make_pair(a,b+1))==arr.end() && s[a].upper_bound(b)!=s[a].end())
	{
		c=a;
		d=*s[a].upper_bound(b);
		if(!iro[{c,d}])
			dfs(c,d);
	}
	if(arr.find(make_pair(a,b-1))==arr.end() && s[a].find(b)!=s[a].begin())
	{
		auto sana=s[a].find(b);
		sana--;
		c=a;
		d=*sana;
		if(!iro[{c,d}])
			dfs(c,d);
	}
}

void add(int a,int b)
{
	aoi.insert(make_pair(a,b));
	s[a].insert(b);
}

void lachryma(int a,int b)
{
	for(int i=0;i<=1;i++)
	{
		lx.emplace_back(a+i);
		ly.emplace_back(b+i);
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,k,a,b,c,d,q,i,j;
	cin>>n>>m>>k;
	
	lachryma(1,1);
	lachryma(1,m);
	lachryma(n,1);
	lachryma(n,m);
	for(i=0;i<k;i++)
	{
		cin>>a>>b;
		lachryma(a,b);
		chie.emplace_back(a,b);
	}
	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>a>>b>>c>>d;
		lachryma(a,b);
		lachryma(c,d);
		qry.emplace_back(a,b,c,d);
	}
	sort(lx.begin(), lx.end());
	lx.resize(unique(lx.begin(), lx.end())-lx.begin());
	sort(ly.begin(), ly.end());
	ly.resize(unique(ly.begin(), ly.end())-ly.begin());
	n=lx.size()-2;
	m=ly.size()-2;
	for(auto &[x,y]:chie)
	{
		x=lower_bound(lx.begin(), lx.end(), x)-lx.begin();
		y=lower_bound(ly.begin(), ly.end(), y)-ly.begin();
		arr.insert(make_pair(x,y));
	}
	for(auto &[a,b,c,d]:qry)
	{
		a=lower_bound(lx.begin(), lx.end(), a)-lx.begin();
		b=lower_bound(ly.begin(), ly.end(), b)-ly.begin();
		c=lower_bound(lx.begin(), lx.end(), c)-lx.begin();
		d=lower_bound(ly.begin(), ly.end(), d)-ly.begin();
		add(a,b);
		add(c,d);
	}
	
	for(auto [x,y]:arr)
	{
		for(i=0;i<8;i++)
		{
			a=x+dir[i][0];
			b=y+dir[i][1];
			if(a>=0 && a<=n && b>=0 && b<=m && arr.find(make_pair(a,b))==arr.end())
				add(a,b);
		}
	}
	
	for(i=1;i<=n;i++)
	{
		if(arr.find(make_pair(i,m))==arr.end())
			add(i,m);
	}
	
	for(auto [x,y]:aoi)
	{
		if(!iro[{x,y}])
		{
			p++;
			dfs(x,y);
		}
	}
	
	for(auto [a,b,c,d]:qry)
	{
		if(iro[{a,b}]==iro[{c,d}])
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	
	return 0;
}
