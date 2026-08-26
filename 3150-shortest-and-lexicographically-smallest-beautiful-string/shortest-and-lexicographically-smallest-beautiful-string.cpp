class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
      // approach is using taking counter and if it equals we store the string sliding window approach and return the smallest amonng them by comparison
      int l=0;
      int cnt=0;
      string ans="";
      for(int r=0;r<s.size();++r){
        if(s[r]=='1'){
            cnt++;
        }
        while(cnt==k){
            string temp = s.substr(l,r-l+1);
            if(ans=="" || (ans.size()==temp.size() && ans>temp ) ||ans.size()>temp.size() ){
                ans=temp;
            }
            if(s[l]=='1'){
                cnt--;
            }
            l++;
        }

      }
return ans;
    }
};