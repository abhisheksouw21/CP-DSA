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

    int t ;
    cin >> t;
    while (t--) {
     int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        if(k%2!=0){
        int c=0;
        for(int i=0;i<n;i++){
           if(a[i]%k==0){
            c++;
            break;
           } 
            a[i]=k-a[i]%k;
        }
        sort(a.begin(),a.end());
        if(c!=0){
            cout << 0 << endl;
        }
        else{
            cout << a[0] << endl;
        }}
        else{
            int ans =0;
            int temp =k;
            for(int i=0;i<n;++i){
                int q = gcd(a[i],k);
                k=k/q;
                a[i]= temp - a[i]%k;
            }
            sort(a.begin(),a.end());
            if(k==1){
                cout << 0 << endl;
            }
            else if(k==2){
                cout << 1 << endl;
            }
            else{
               cout << min(a[0],2) << endl;
            }
        }
        

    } 
}