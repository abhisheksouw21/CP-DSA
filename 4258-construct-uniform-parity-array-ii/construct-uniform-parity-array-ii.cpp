class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // approach gemini ne di
        bool f = false;
        int mn=nums1[0];
        for(int i : nums1){
            mn=min(mn,i);
            if(i%2!=0){
                f=true;
            }
        }
       return (mn%2!=0) || !f; 
    }
};