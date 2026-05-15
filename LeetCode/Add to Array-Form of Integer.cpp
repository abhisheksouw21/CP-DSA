class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(),num.end());
        int i=0;
        while(i<num.size()|| k>0){
            if(i<num.size()){
                int sum = num[i]+k%10;
                num[i]=sum%10;
                k= k/10+sum/10;
            }
            else{
                num.push_back(k%10);
                k/=10;
            }
            i++;
        }
        reverse(num.begin(),num.end());
        return num;
    }
};