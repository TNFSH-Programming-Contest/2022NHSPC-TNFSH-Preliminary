#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("input.in", "r", stdin);

	cin >> n;
	int o = 0, e = 0;
	for(int i=0,x;i<2*n;i++){
		cin >> x;
		if(x&1)
			o++;
		else
			e++;
	}
	cout << (e&1 ? "No\n" : "Yes\n");
}
