#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define tc(t) ll t;cin >> t; while(t--)
#define pb push_back
#define fi first
#define se second
#define debug1(x) cout<<#x<<" = "<<x<<'\n';
#define debug2(x, y) cout << #x << " = " << x << "   " << #y << " = " << y << "\n";
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);

ll pallers(ll *a, ll n, ll x) {
	ll curr = 0;
	ll num = 0; 
	for(ll i = 0; i<n; i++) {
		curr += a[i];
		if(curr > x) {
			curr = a[i];
			num ++;
		}
	}
	return (num+1);
}
ll solve(ll *a, ll n, ll k, ll low, ll high) {
    
	while(low < high) {
		ll mid = low + (high-low)/2;
		ll num = pallers(a, n, mid);
		
		if(num <= k) high = mid;
		else low = mid + 1;
	}
	return low;
}

int main() {_
	tc(t) {
		ll k, n;
		
		cin >> n;
		ll sum = 0;
		ll a[n] = {};
		for(ll i = 0; i<n; i++) {
			cin >> a[i];
			sum += a[i];
		} 
		cin >> k;
		if(k > n) {
		    cout<<"-1\n";
		}
		else {
			
			ll ma = *max_element(a, a+n);
			ll ans = solve(a, n, k, ma, sum);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
