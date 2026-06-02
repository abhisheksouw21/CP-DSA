class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
       vector<int> ans;
        int n = arr.size();
        for(int i=n;i>1;--i){
            int idx=0;
            for(int j=0;j<n;++j){
                if(arr[j]==i){
                    idx=j;
                    break;
                }
            }
            if(idx==i-1){
                continue;
            }
            if(idx!=0){
             reverse(arr.begin(), arr.begin() + idx + 1);
                ans.push_back(idx+1);
            }
              reverse(arr.begin(),arr.begin()+i);
                ans.push_back(i);
        }
        return ans;
        
        
    }
};