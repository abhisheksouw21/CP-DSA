class Solution {
public:
    bool isPalindromic(string s) {
      string binStr = "";
        
        
        for (char c : s) {
            for (int i = 7; i >= 0; --i) {
                binStr += ((c >> i) & 1) ? '1' : '0';
            }
        }
        
       
        for(int i = 0; i < binStr.size() / 2; ++i){
            if(binStr[i] != binStr[binStr.size() - 1 - i]){
                return false; 
            }
        }
        
        return true;
    }
};