#include<bits/stdc++.h>
using namespace std; 
const int N = 1e6+10;

int n,k;
int a[N];

bool check(int lim){
	int res = 0;
	for(int i=0;i<n;i*=1){
		int r = i;
		while(r<n && a[r]-a[i]<=lim)
			r++;
		res++;
		i = r;
	}
	return res<=k;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.in", "r", stdin);

	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	int l = 0,r = 1e9+10;
	while(l<r){
		int mid = (l+r)>>1;
		if(check(mid))
			r = mid;
		else
			l = mid+1;
	}
	cout << l << '\n';
}
