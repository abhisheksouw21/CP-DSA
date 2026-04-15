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
    
     string s1;
	cin >> s1;
	string s2;
	cin >> s2;
    map<char,int>m1;
    map<char,int>m2;
    for(int i=0;i<s1.size();++i){
        m1[s1[i]]++;
    }
	 for(int i=0;i<s2.size();++i){
        m2[s2[i]]++;
    }
    int ans =0;
    for(char i='a';i<='z';++i){
        ans+=min(m1[i],m2[i]);
        if(m1[i]==0 && m2[i]!=0){
            ans=-1;
            break;
        }
    }
    if(ans<=0){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
	
    }

    