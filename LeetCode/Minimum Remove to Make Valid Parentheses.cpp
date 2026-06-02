class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int>r;
        stack<int>st;
       for(int i=0;i<s.size();++i){
        if(s[i]=='('){
            st.push(i);
        }
        if(s[i]==')'){
            if(st.empty()){
                r.insert(i);
            }
            else{
                st.pop();
            }
        }
       }
       while(!st.empty()){
        r.insert(st.top());
         st.pop();
       }
       string ans="";
       for(int i=0;i<s.size();++i){
        if(r.find(i)==r.end()){
            ans+=s[i];
        }

       }
       return ans;
    }
};