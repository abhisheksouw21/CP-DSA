class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
         int l=0;
         int h=matrix[0].size() - 1;
       while(l < matrix.size() && h >= 0) {
           
            if(target<matrix[l][h]){
                h--; 
            }
            else if(target>matrix[l][h]){
                  l++;     
            }
            else{
                return true;
            }
         }
       return false;
    }
};