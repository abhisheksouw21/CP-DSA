class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.length();
        int m = station.length();
        
        vector<int>a(n);
         vector<int>b(n);
         int j=0;
         for(int i=0;i<n;++i){
            while(j<m && skill[i]!=station[j]){
                j++;
            }
            a[i]=j;
            j++;
         }
         j=m-1;
         for(int i=n-1;i>=0;--i){
            while(j>=0 &&skill[i]!=station[j] ){
                j--;
            }
            b[i]=j;
            j--;
         }
         int ans=0;
for(int i=1;i<n;++i){
    ans= max(ans,b[i]-a[i-1]);
}
return ans;
    }
};