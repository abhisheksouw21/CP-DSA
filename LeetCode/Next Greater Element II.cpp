class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
          vector<int>m(nums.size());
        stack<int>st;
        for(int i=2*nums.size()-1;i>=0;--i){
                   int idx=i%nums.size();
                   int temp=nums[idx];
              while(!st.empty() && st.top()<=temp){
                st.pop();
              }
              if(i<nums.size()){
              if(st.empty()){
                m[i]=-1;
              }
              else{
                m[i]=st.top();
              }
              }
              st.push(temp);
        }
      
       return m;
    }
};