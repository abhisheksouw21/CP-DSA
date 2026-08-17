class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        for(int i=0;i<arrivalTime.size();++i){
            arrivalTime[i]= arrivalTime[i]%period;
        }
        int r=0;
        for(auto i : lights){
            r=max(i,r);
        }
        int ans=0;
        for(auto i: arrivalTime){
            if(i<r){
                continue;
            }
            ans= max(ans,period-i);
        }
        return ans;
    }
};