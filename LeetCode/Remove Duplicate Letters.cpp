class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>v(26,0);
        vector<bool>a(26,false);
        string result ="";
        for(int i=0;i<s.size();++i){
            v[s[i]-'a']=i;
        }
         for(int i=0;i<s.size();++i){
           char c=s[i];
           if(a[c-'a'])continue;
           while(!result.empty() && result.back()>c && v[result.back()-'a']>i){
            a[result.back()-'a']=false;
            result.pop_back();
           }
           result.push_back(c);
            a[c-'a']=true;
        }
        return result;
    }
};