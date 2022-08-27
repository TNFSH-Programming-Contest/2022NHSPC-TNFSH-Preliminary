#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

void gen_sorted_task(){
	int test_size = rnd.next(3);
	int n1 = rnd.next(1,1000), n2 = rnd.next(1,1000);
	int n = n1*n2, n_sqrt = (int)sqrt(n);
	int k1 = rnd.next(1,n_sqrt), k2 = rnd.next(1,n_sqrt);
	if(test_size==1)
		k1 *= k2;
	cout << n << ' ' << k1 << '\n';
	for(int i=1;i<=n;i++)
		cout << i << " \n"[i==n];
}

void gen_task(int mxN, bool Max){
	int n = rnd.next(1,mxN);
	if(Max)
		n = mxN;
	int k = rnd.next(1,n);
	cout << n << ' ' << k << '\n';
	for(int i=1;i<=n;i++)
		cout << rnd.next(1,1000000000) << " \n"[i==n];	
}

int main(int argc, char *argv[]){
	ios::sync_with_stdio(0);
	cin.tie(0);

	registerGen(argc, argv, 1);
	
	int task_num = atoi(argv[1]);
	if(task_num==1)
		gen_task(7,(argv[2]=="max"));
	else if (task_num==2)
		gen_sorted_task();
	else if(task_num==3)
		gen_task(1000,(argv[2]=="max"));
	else
		gen_task(1000000,(argv[2]=="max"));
}
