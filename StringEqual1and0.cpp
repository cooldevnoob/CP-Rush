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
		int n;
		cin >> n;
		int a[n+1] = {};
		int pre[n+1] = {}; 
		for(int i = 1; i<=n; i++) {
			cin >> a[i];
			if(a[i] == 1) pre[i] += 1;
			else pre[i] -= 1;
		}
		int pos[n+1] = {};
		int neg[n+1] = {};
		for(int i = 1; i<=n; i++) {
			if(pre[i] >= 0) pos[pre[i]] = i;
			else neg[pre[i]] = i; 
		}
		int ans = 0;
		for(int i = 1; i<=n; i++) {
			int x = pre[i-1];
			debug1(x)
			if(x >= 0) {
				ans = max(ans, pos[x] - i + 1);
			}
			else {
				ans = max(ans, neg[x] - i + 1);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
