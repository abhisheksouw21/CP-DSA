class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int size = flowerbed.size();

        if(size == 1){
            if(flowerbed[0] == 0) cnt++;
            return cnt >= n;
        }

        if(flowerbed[0] == 0 && flowerbed[1] == 0){
            flowerbed[0] = 1;
            cnt++;
        }

        for(int i = 1; i < size - 1; ++i){
            if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                cnt++;
            }
        }

        if(flowerbed[size-1] == 0 && flowerbed[size-2] == 0){
            cnt++;
        }

        return cnt >= n;
    }
};