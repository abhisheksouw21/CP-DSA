class Solution {
public:
    bool matches(int a[26],int b[26]){
        for(int i=0;i<26;++i){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        int a[26]={0},b[26]={0};
        for(int i=0;i<s1.size();++i){
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
        }
        for(int i=0;i<=s2.size()-s1.size();++i){
            if(matches(a,b)) return true;
           if(i+s1.size()<s2.size()){
            b[s2[i+s1.size()]-'a']++;
            b[s2[i]-'a']--;
           }
        }
      return false;
    }
};