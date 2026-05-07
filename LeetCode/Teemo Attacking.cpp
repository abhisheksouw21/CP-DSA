class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=duration;
        for(int i=0;i<timeSeries.size()-1;++i){
            int temp=timeSeries[i]+duration -1;
            if(temp<timeSeries[i+1]){
                ans+=duration;
            }
            else{
                ans+=duration;
                ans-=(temp-timeSeries[i+1]+1);
            }
        }
        return ans; 
    }
};