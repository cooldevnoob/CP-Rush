#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define tc(t) int t;cin >> t; while(t--)
#define pb push_back
#define fi first
#define se second
#define debug1(x) cout<<#x<<" = "<<x<<'\n';
#define debug2(x, y) cout << #x << " = " << x << "   " << #y << " = " << y << "\n";
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);

int main() {_
	tc(t) {
		ll n;
		cin >> n;
		ll a[n+1] = {};
		ll pre[n+1] = {}; 
		map<ll, ll> mp;
		for(int i = 1; i<=n; i++) {
			cin >> a[i];
			pre[i] = pre[i-1] + a[i];
			mp[pre[i]] ++;
		}
		ll ans = 0;
		
		for(int i = 1; i<=n; i++) {
			if(i == 1) ans += mp[0];
			else {
				mp[pre[i-1]]--;
				ans += mp[pre[i-1]];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
