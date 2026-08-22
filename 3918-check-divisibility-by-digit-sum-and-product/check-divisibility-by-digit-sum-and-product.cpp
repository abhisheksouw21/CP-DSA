class Solution {
public:
    bool checkDivisibility(int n) {
         string s = to_string(n);
         int a=0;
         for(char i :s){
int x = i - '0';
           a+=x;
         }
         int b=1;
         for(char i :s){
int x = i - '0';
           b*=x;
         }
      return n%(a+b)==0;
    }
};