class Solution {
private:
    void backtrack(string& s, int idx, int parts, string currentIP, vector<string>& ans) {
        
        if (idx == s.length() && parts == 4) {
            currentIP.pop_back(); 
            ans.push_back(currentIP);
            return;
        }
        
       
        if (idx == s.length() || parts == 4) {
            return;
        }
        
        string part = "";
        for (int i = idx; i < idx + 3 && i < s.length(); ++i) {
            part += s[i];
            
            if (part.length() > 1 && part[0] == '0') break; 
            
            if (stoi(part) <= 255) {
                backtrack(s, i + 1, parts + 1, currentIP + part + ".", ans);
            }
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
      
        if (s.length() < 4 || s.length() > 12) {
            return ans;
        }
        
        backtrack(s, 0, 0, "", ans);
        return ans;
    }
};