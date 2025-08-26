#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <numeric>      // gcd, accumulate
#include <functional>
#include <iomanip>      // setprecision
#include <sstream>
#include <tuple>
#include <bitset>
#include <limits>
#include <chrono>
#include <random>

using namespace std;

// #define int long long
// #define endl '\n'
// #define pb push_back
// #define all(x) (x).begin(), (x).end()
// #define sz(x) (int)(x).size()



void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


signed main() {
	int n,m,mn,mx;
	cin >> n >> m >> mn >> mx;
	vector<int>v(m);
	for(int i=0;i<m;++i){
	    cin >> v[i];
	}
	vector<int>a;
	a.push_back(mn);
	a.push_back(mx);
	int c=0;
for(int i=0;i<m;++i){
	    if(v[i]==mx){
	       v[i]=-1;
	       break;
	    }
	}
	for(int i=0;i<m;++i){
	    if(v[i]==mn){
	       v[i]=-1;
	       break;
	    }
	}
	for(int i=0;i<m;++i){
	    if( v[i]>mx && v[i]!=-1){
	        c++;
	        break;
	    }
	    else if(v[i]<mn && v[i]!=-1){
	        c++;
	        break;
	    }
	    else if(v[i]==-1){
	        continue;
	    }
	    else{
	        a.push_back(v[i]);
	    }
	}
	if(c!=0){
	   	    cout << "Incorrect" << endl;
	}
	else if(a.size()<=n){
	    cout << "Correct" << endl;
	}
	else{
	    cout << "Incorrect" << endl;
	}
	
	
	
 
}
