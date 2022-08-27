
#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
const int mxN = 1e6, V = 1e9;

int main(int argc,char *argv[]){
	registerValidation(argc,argv);

	int n = inf.readInt(1,mxN,"n");
	inf.readSpace();
	int k = inf.readInt(1,n,"k");
	inf.readEoln();

	for(int i=0;i<n;i++){
		if(i)
			inf.readSpace();
		int x = inf.readInt(1,V,"a_i");
		ensuref(x==i+1, "a_i not equals to i\n");
	}
	inf.readEoln();
	inf.readEof();
}
