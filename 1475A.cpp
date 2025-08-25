#include <bits/stdc++.h>;
using namespace std;
#define int long long
signed main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
       string s;
       cin >> s;
         int ans = 0;
         if(s[0] == '0'){
            ans+=1;
    }
    else{
        ans+=2;
    }
    for(int i = 1; i < n; i++){
        if(s[i] == '1' && s[i-1] == '0'){
            ans+=2;
        }
        else if(s[i] == '0' && s[i-1] == '1'){
            ans+=2;
        }
        else{
            ans+=1;
        }
    }
    int c=0;
    for(int i = 1; i < n; i++){
        if(s[i] != s[i-1]){
            c++;
        }
    }
    if(s[0]=='1'){
        c++;
    }
    if(c<2){
        cout << ans << endl;
    }
    else if(c==2){
        cout << ans-1 << endl;
    }
    else{
        cout << ans-2 << endl;
    }
        
    }
    
}