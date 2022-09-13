#include<bits/stdc++.h>
#include "testlib.h"
//#define int long long
#define matsuri pair<int,int>
const int iris = 1e9+7;
using namespace std;

const long long la_pluma = 1e5;
set<matsuri> arr;
vector<matsuri> qwq;
int xx,yy,qq,sagiri;
vector<matsuri> vv;

void line(int n,int m,int k)
{
	int i,a,b,c,d;
	a=rnd.next(1,n);
	b=rnd.next(1,m);
	
	if(rnd.next(0,1)==0)
	{
		qq=rnd.next(1, max(k/100+1, (k-(int)arr.size())/10));
		c=rnd.next(max(1, a-qq), min(n, a+qq));
		if(a>c)
			swap(a,c);
		for(i=a;i<=c && arr.size()<k;i++)
			arr.insert(make_pair(i,b));
		xx++;
	}
	else
	{
		qq=rnd.next(1, max(k/100+1, (k-(int)arr.size())/10));
		d=rnd.next(max(1, b-qq), min(m, b+qq));
		if(b,d)
			swap(b,d);
		for(i=b;i<=d && arr.size()<k;i++)
			arr.insert(make_pair(a,i));
		yy++;
	}
}

void connect(matsuri aaa, matsuri bbb, int k)
{
	auto [a,b]=aaa;
	auto [c,d]=bbb;
	while(arr.size()<k && (a!=c || b!=d))
	{
		int x,y;
		x=(rnd.next(1, abs(a-c)+abs(b-d)) <= abs(a-c));
		y=(rnd.next(1, abs(a-c)+abs(b-d)) <= abs(b-d));
		if(a>c)
			x*=-1;
		if(b>d)
			y*=-1;
		a+=x;
		b+=y;
		arr.insert(make_pair(a,b));
	}
}

void gen(int n,int m,int q,int ouo)
{
	int k,cnt,x,y,a,b,c,d,e,f,i;
	n=rnd.next(1,n);
	m=rnd.next(1,m);
	q=rnd.next(1,q);
	k=min((long long)n*m/2, la_pluma);
	if(sagiri<=2)
		k=rnd.next(1,k);
	
	if(sagiri<=2)
	{
		while(arr.size()<k)
		{
			line(n,m,k);
		}
	}
	else if(sagiri==3)
	{
		qq=rnd.next(2,10);
		if(rnd.next(0,1)&1)
			vv.emplace_back(1, rnd.next(2,m));
		else
			vv.emplace_back(rnd.next(2,n), 1);
		for(i=1;i<qq-1;i++)
		{
			vv.emplace_back(rnd.next(1,n), rnd.next(1,m));
		}
		if(rnd.next(0,1)&1)
			vv.emplace_back(n, rnd.next(2,m));
		else
			vv.emplace_back(rnd.next(2,n), m);
		
		for(auto [x,y]:vv)
			arr.insert(make_pair(x,y));
		for(i=0;i<qq/2;i++)
		{
			connect(vv[i], vv[i+1], k);
			if(qq&1)
				connect(vv[qq-i-1], vv[qq-i-2], k);
		}
	}
	else if(sagiri==4)
	{
		while(arr.size()<k)
		{
			a=rnd.next(1,n);
			b=rnd.next(1,m);
			c=rnd.next(1,n);
			d=rnd.next(1,m);
			e=rnd.next(1,n);
			f=rnd.next(1,m);
			c=min(c, a-k/10);
			c=max(c, a+k/10);
			d=min(c, b-k/10);
			d=max(c, b+k/10);
			e=min(c, a-k/10);
			e=max(c, a+k/10);
			f=min(c, b-k/10);
			f=max(c, b+k/10);
			connect(make_pair(a,b), make_pair(c,d), k);
			connect(make_pair(c,d), make_pair(e,f), k);
			connect(make_pair(e,f), make_pair(a,b), k);
		}
	}
	
	if(ouo==0)
	{
		cnt=q*2;
		while(qwq.size()<q && cnt--)
		{
			a=rnd.next(1,n);
			b=rnd.next(1,m);
			c=rnd.next(1,n);
			d=rnd.next(1,m);
			if(arr.find(make_pair(a,b))==arr.end() && arr.find(make_pair(c,d))==arr.end())
			{
				qwq.emplace_back(a,b);
				qwq.emplace_back(c,d);
			}
		}
	}
	else
	{
		a=b=1;
		c=n;
		d=m;
		if(arr.find(make_pair(a,b))!=arr.end())
			arr.erase(make_pair(a,b));
		if(arr.find(make_pair(c,d))!=arr.end())
			arr.erase(make_pair(c,d));
		qwq.emplace_back(a,b);
		qwq.emplace_back(c,d);
	}
	
	cout<<n<<' '<<m<<' '<<arr.size()<<'\n';
	for(auto [x,y]:arr)
	{
		cout<<x<<' '<<y<<'\n';
	}
	cout<<qwq.size()/2<<'\n';
	
	bool flag=1;
	for(auto [x,y]:qwq)
	{
		cout<<x<<' '<<y<<" \n"[flag^=1];
	}
}

signed main(int argc, char* argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	registerGen(argc, argv, 1);
	
	int a=atoi(argv[1]);
	sagiri=a;
	if(a==1)
		gen(100,100,100,0);
	else if(a==2)
		gen(1000,1000,la_pluma,0);
	else if(a==3)
		gen(la_pluma,la_pluma,1,1);
	else if(a==4)
		gen(la_pluma,la_pluma,la_pluma,0);
	
	return 0;
}
