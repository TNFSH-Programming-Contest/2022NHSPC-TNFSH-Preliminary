#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> vec;
int check(int n){
	int ans = 0, l = 0, r = l+1;
	while (l != vec.size()-1){
		while (vec[r] - vec[l] <= n && r < vec.size()-1){
			r++;
		}
		ans++;
		l = r;
		r++;
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, ans = 123;
    cin >> n >> m;
    vec.resize(n);
    for (int i = 0; i < n; i++){
    	cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int l = 0, r = 1e9, mid;
    while (l < r){
    	mid = l + (r-l)/2;
    	if (check(mid) <= m){
    		ans = mid;
    		r = mid;
    	}
    	else{
    		l = mid+1;
    	}
    }
    cout << ans << '\n';
    
    

    return 0;
}

// from https://toj.tfcis.org/oj/chal/295398/