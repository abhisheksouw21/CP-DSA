class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }
        vector<int> m(128, 0);
        for (char c : t) {
            m[c]++;
        }
        int l=0,r=0;
        int ms=0,ans=INT_MAX;
        int cnt=t.size();
        while(r<s.size()){
            if(m[s[r]]>0){
                cnt--;
            }
            m[s[r]]--;
            r++;
            while(cnt==0){
                if(r-l<ans){
                    ms=l;
                    ans=r-l;
                }
                m[s[l]]++;
                if(m[s[l]]>0){
                    cnt++;
                }
                l++;
            }

        }
        return ans== INT_MAX ? "" : s.substr(ms,ans);
    }
};