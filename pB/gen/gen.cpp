#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
const int N = 1e5, V = 2499999;

void gen_task1(){
	int n = rnd.next(1,N), oe = rnd.next(2);
	cout << n << '\n';
	n *= 2;
	for(int i=0;i<n;i++)
		cout << 2*rnd.next(1,N)+oe << " \n"[i==n-1];
}

void gen_task(){
	int n = rnd.next(1,N), ok = rnd.next(5);
	vector<int>v;
	cout << n << '\n';
	if(ok<2){
		int k = rnd.next(n+1);
		for(int i=0;i<2*k;i++)
			v.push_back(2*rnd.next(1,V));
		for(int i=0;i<2*(n-k);i++)
			v.push_back(2*rnd.next(1,V)+1);
	}
	else{
		int k = rnd.next(1,n-1);
		for(int i=0;i<2*k-1;i++)
			v.push_back(2*rnd.next(1,V));
		for(int i=0;i<2*(n-k)+1;i++)
			v.push_back(2*rnd.next(1,V)+1);
	}
	shuffle(v.begin(), v.end());
	for(int i=0;i<2*n;i++)
		cout << v[i] << " \n"[i==2*n-1];
}

int main(int argc,char *argv[]){
	registerGen(argc,argv,1);

	int task_num = atoi(argv[1]);
	if(task_num==1)
		gen_task1();
	else
		gen_task();
}
