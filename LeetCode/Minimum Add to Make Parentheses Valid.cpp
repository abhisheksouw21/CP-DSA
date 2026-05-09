class Solution {
public:
    int minAddToMakeValid(string s) {
        int o=0,c=0;
        for(char ch : s){
            if(ch=='(')o++;
            else{
                if(o==0)c++;
                else o--;
            }
        }
        return o+c;
    }
};