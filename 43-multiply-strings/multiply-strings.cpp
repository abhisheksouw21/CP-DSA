class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n=num1.size(),m=num2.size();
        vector<int>res(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int a=i+j;
                int b= i+j+1;
                int sum= (num1[i] - '0') * (num2[j] - '0') + res[b];
                res[b]=sum%10;
                res[a]+=sum/10;

            }
        }
        string ans="";
        int x=0;
        while(x<res.size() && res[x]==0){
            x++;
        }
        while(x<res.size()){
            ans+= to_string(res[x]);
            x++;
        }
        return ans;
    }
};