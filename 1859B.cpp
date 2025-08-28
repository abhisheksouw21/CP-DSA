
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
signed main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int>q;
	    int mn = INT_MAX;
	    int ans =0;
	    while(n--){
	        int m;
	        cin >> m;
	        vector<int>v(m);
	        for(int i=0;i<m;++i){
	            cin >> v[i];
	        }
	        for(int i=0;i<m;++i){
	            if(v[i]<mn){
	                mn = v[i];
	            }
	        }
	        sort(v.begin(),v.end());
	        q.push_back(v[1]);
	        
	    }
	    ans+=mn;
	    sort(q.begin(),q.end());
	    for(int i=1;i<q.size();++i){
	        ans+=q[i];
	    }
	    cout << ans << endl;
	}
 
}
