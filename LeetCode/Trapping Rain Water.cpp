class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>rmax(n);
        vector<int>lmax(n);
        int a=height[0],b=height[n-1];
        rmax[n-1]=0;
        lmax[0]=0;
        for(int i=1;i<n;++i) {
             rmax[n-1-i]=b;
             b=max(b,height[n-i-1]);
      lmax[i]=a;
             a=max(a,height[i]);
        }
        int ans=0;
        for(int i=0;i<n;++i){
            int temp=min(rmax[i],lmax[i]);
            if((temp-height[i])>0){
                ans+=temp-height[i];
            }
        }
        return ans;
    }
};