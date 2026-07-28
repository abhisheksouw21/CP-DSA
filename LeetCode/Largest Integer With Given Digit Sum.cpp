class Solution {
public:
    int largestInteger(int n, int s) {
        if(n*9<s){
            return -1;
        }
        string ans="";
        while(n>0){
            if(s>9){
                ans+='9';
                s-=9;
            }
            else{
ans += to_string(s);
                s=0;
            }
            n--;
        }
        int num = stoi(ans);
        return num;
    }
};