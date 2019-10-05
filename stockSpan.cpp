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
		for(int i = 1; i<=n; i++) cin >> a[i];
		stack<pair<int, int > > st;
		int ans[n+1] = {};
		ans[1] = 1;
		st.push({a[1], 1});
		
		for(int i = 2; i<=n; i++) {
			int tp = st.top().fi;
			if(a[i] < tp) {
				ans[i] = i - st.top().se;
				st.push({a[i], i});
			}
			else {
				int flag = 0;
				while(!st.empty()) {
					int tp = st.top().fi;
					if(tp <= a[i]) {
						st.pop();
					}
					else {
						ans[i] = i - st.top().se;
						st.push({a[i], i});
						flag = 1;
					}
					if(flag) break;
				}
				if(flag == 0) {
					ans[i] = i;
					st.push({a[i], i});
				}
			}
		}
		for(int i = 1; i<=n; i++) cout<<ans[i]<<' '; cout<<'\n';
	} 
	return 0;
}
