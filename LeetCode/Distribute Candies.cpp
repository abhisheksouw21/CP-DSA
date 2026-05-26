class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
     bitset<200005> seen;
        int uniqueCount = 0;
        int limit = candyType.size() / 2;
        
        for (int candy : candyType) {
            if (!seen[candy + 100000]) {
                seen[candy + 100000] = true;
                uniqueCount++;
                
                if (uniqueCount == limit) {
                    return limit;
                }
            }
        }
        
        return min(uniqueCount, limit);

    }
};