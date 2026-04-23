class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int,vector<int>,greater<int>> heap;
       int cs=0;
       for(int num : nums){
        if(cs==k){
            if(heap.top()<num){
               heap.pop();
               heap.push(num);
            }
        }
        else{
                          heap.push(num);
                          cs++; 
        }
       }
       return heap.top();
    }
};