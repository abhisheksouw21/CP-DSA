class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>pse;
        stack<int>st;
        for(int i=0;i<arr.size();++i){
              while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
              }
              if(st.empty()){
              pse.push_back(-1);
              }
              else{
               pse.push_back(st.top());
              }
              st.push(i);
        }
        
        while(!st.empty())st.pop();
        vector<int>nse;
         for(int i=arr.size()-1;i>=0;--i){
              while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
              }
              if(st.empty()){
              nse.push_back(arr.size());
              }
              else{
               nse.push_back(st.top());
              }
              st.push(i);
        }
        reverse(nse.begin(), nse.end());
        long long ans = 0;
        long long MOD = 1e9 + 7;
        
        for (int i = 0; i < arr.size(); ++i) {
            long long l = i - pse[i];
            long long r = nse[i] - i;
            long long t = (l * r) % MOD;
            ans = (ans + arr[i] * t) % MOD;
        }
        
        return ans;
    }

};