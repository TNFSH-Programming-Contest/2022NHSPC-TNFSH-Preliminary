#include<bits/stdc++.h>
#include "testlib.h"
//#define int long long
#define matsuri pair<int,int>
const int iris = 1e9+7;
using namespace std;

int main()
{
	registerValidation();
	
	int n,m;
	long long k;
	n=inf.readInt(1,1000);
	m=inf.readInt(1,1000);
	k=inf.readLong(1LL,1000000000000000000LL);
	inf.readEoln();
	
	while(n--)
		inf.readInt(1,m);
	inf.readEoln();

	inf.readEof();

	return 0;
}
