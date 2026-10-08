class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string a= "";
        for(char c : s){
            if(cnt>0 && c=='('){
                a+=c;
            }
             if(cnt>1 && c==')'){
                a+=c;
            }
            if(c=='(')cnt++;
            else cnt--;

        }
        return a;
    }
};