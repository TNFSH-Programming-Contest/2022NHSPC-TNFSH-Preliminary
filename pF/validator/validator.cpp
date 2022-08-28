#include<bits/stdc++.h>
#include "testlib.h"
//#define int long long
#define matsuri pair<int,int>
const int iris = 1e9+7;
using namespace std;

int main()
{
	registerValidation();
	
	int n,m,q,k,a,b,c,d;
	n=inf.readInt(1,1000000000);
	m=inf.readInt(1,1000000000);
	inf.readEoln();
	for(int i=0;i<k;i++)
	{
		a=inf.readInt(1,n);
		b=inf.readInt(1,m);
		inf.readEoln();
	}
	q=inf.readInt(1,1000000);
	for(int i=0;i<q;i++)
	{
		a=inf.readInt(1,n);
		b=inf.readInt(1,m);
		c=inf.readInt(1,n);
		d=inf.readInt(1,m);
		inf.readEoln();
	}

	inf.readEof();

	return 0;
}
