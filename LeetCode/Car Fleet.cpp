class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,double>>v(n);
        for(int i=0;i<n;++i){
            v[i].first=position[i];
            v[i].second=  double(target-position[i])/speed[i];
        }
        sort(v.begin(),v.end());
       int ans = 0;
        double max_time = 0.0;

        // Iterate backward from the car closest to the target
        for (int i = n - 1; i >= 0; --i) {
           
            if (v[i].second > max_time) {
                ans++;
                max_time = v[i].second; 
            }
        }

        return ans;

    }
};