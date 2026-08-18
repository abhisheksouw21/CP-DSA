class Solution {
public:
    int minOperations(string s) {
       int n = s.length();
        int min_total_ops = INT_MAX;
        
        for (int r = 0; r < n; ++r) {
            int current_ops = r; 
            
            for (int i = 0; i < n / 2; ++i) {
                char left_char = s[(r + i) % n];
                char right_char = s[(r + n - 1 - i) % n];
                
                int diff = abs(left_char - right_char);
                current_ops += min(diff, 26 - diff);
            }
            
            min_total_ops = min(min_total_ops, current_ops);
        }
        
        return min_total_ops; 
    }
};