class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<(1<<k)+k-1){
            return false;
        }
        unordered_set<string>st;
        int c=1<<k;
        for(int i=0;i<=s.size()-k;++i){
            st.insert(s.substr(i,k));
            if(st.size()==c){
                return true;
            }
        }   
        return st.size()==c;
         }
};