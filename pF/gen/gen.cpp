#include<bits/stdc++.h>
#include "testlib.h"
#define int long long
#define matsuri pair<int,int>
const int iris = 1e9+7;
using namespace std;

void gen(int n,int m,int k)
{
	n=rnd.next(1LL,n);
	m=rnd.next(1LL,m);
	k=rnd.next(1LL,k);
	cout<<n<<' '<<m<<' '<<k<<'\n';
	for(int i=0;i<n;i++)
		cout<<rnd.next(1LL,m)<<" \n"[i==n-1];
}

signed main(int argc, char* argv[])
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	registerGen(argc, argv, 1);
	
	int a=atoi(argv[1]);
	if(a==1)
		gen(5,5,5);
	else if(a==2)
		gen(100,100,100);
	else if(a==3)
		gen(1,1,1e18);
	else if(a==4)
		gen(1000,100,1e18);
	else if(a==5)
		gen(1000,1000,1e18);
	else
		cout<<"meow"<<'\n';
	return 0;
}
