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
    fastIO();

    int t;
    cin >> t;
    while (t--) {
     string s1,s2;
     cin >> s1 >> s2;
     int ans =0;
        for(int len=1;len<=min(s1.size(),s2.size());len++){
           for(int i=0;i+len<=s1.size();++i){
                for(int j=0;j+len<=s2.size();++j){
                     if(s1.substr(i,len)==s2.substr(j,len)){
                          ans = max(ans,len);
                     }
                }
           }
        }
        cout << s1.size()+s2.size()-2*ans << endl;

}
}
