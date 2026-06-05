class Solution {
public:
    bool f(int mid,vector<int>v){
        int n=v.size();
        for(int i=0;i<n;++i){
            if(v[i]>=mid){
                int a=n-i;
                return a>=mid;
            }
        }
        return false;
    }
    int hIndex(vector<int>& citations) {
      sort(citations.begin(),citations.end());
      int l=0;
      int h= citations.back();
      int ans=0;
      while(l<=h){
        int mid = (l+h)/2;
        if(f(mid,citations)){
            ans=max(ans,mid);
            l=mid+1;
        }
        else{
            h=mid-1;
        }
      } 
       return ans;
    }
};