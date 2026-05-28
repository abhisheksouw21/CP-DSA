class Solution {
public:
    int candy(vector<int>& ratings) {
     int totalCandies=1;
     int up=1;
     int down=0;
     int peak=1;
     for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
              
                up++;
                peak = up;
                down = 0;
                totalCandies += up;
            } else if (ratings[i] == ratings[i - 1]) {
               
                up = 1;
                down = 0;
                peak = 1;
                totalCandies += 1;
            } else {
              
                up = 1;
                down++;
               
                totalCandies += down + (peak <= down ? 1 : 0);
            }
        }
        
        return totalCandies;
    }
};