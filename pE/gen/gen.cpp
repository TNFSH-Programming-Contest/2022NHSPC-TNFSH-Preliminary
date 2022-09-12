#include<bits/stdc++.h>
#include "testlib.h"
//#define int long long
#define matsuri pair<int,int>
const int iris = 1e9+7;
using namespace std;

const long long la_pluma = 1e5;
set<matsuri> arr,qwq;

void gen(int n,int m,int q,int ouo)
{
	int k,cnt,x,y,a,b,c,d;
	k=min((long long)n*m/2, la_pluma);
	if(n==100)
		k=k*4/5;
	cnt=k*2;
	while(arr.size()<k && cnt--)
	{
		x=rnd.next(1,n);
		y=rnd.next(1,m);
		arr.insert(make_pair(x,y));
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
				qwq.insert(make_pair(a,b));
				qwq.insert(make_pair(c,d));
			}
		}
	}
	
	cout<<n<<' '<<m<<' '<<arr.size()<<'\n';
	for(auto [x,y]:arr)
	{
		cout<<x<<' '<<y<<'\n';
	}
	cout<<qwq.size()<<'\n';
	
	bool f=1;
	for(auto [x,y]:qwq)
	{
		cout<<x<<' '<<y<<" \n"[f^=1];
	}
}

signed main(int argc, char* argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	registerGen(argc, argv, 1);
	
	int a=atoi(argv[1]);
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
