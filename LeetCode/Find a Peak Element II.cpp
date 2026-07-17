class Solution {
public:
    int maxrow(vector<vector<int>> mat,int m){
        int n=mat.size();
        int mx=INT_MIN;
        int idx=-1;
        for(int i=0;i<n;++i){
            if(mat[i][m]>mx){
                mx=mat[i][m];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0;
        int h=m-1;
        while(l<=h){
            int mid=(l+h)/2;
            int r=maxrow(mat,mid);
             int left = mid - 1 >= 0 ? mat[r][mid - 1] : INT_MIN;
              int right = mid + 1 < m ? mat[r][mid + 1] : INT_MIN;
             int x= mat[r][mid];
             if(x>left && x>right){
                return {r,mid};
             }
             else if(left>x){
                h=mid-1;
             }
             else{
                l=mid+1;
             }
        }
        return {-1,-1};
    }
};