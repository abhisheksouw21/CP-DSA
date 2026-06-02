class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> freq(128);
        for (int i = 0; i < 128; i++) {
            freq[i] = {0, i};
        }
        
      
        for (char c : s) {
            freq[c].first++;
        }
        
       
        sort(freq.rbegin(), freq.rend());
        
     
        string result;
        for (auto p : freq) {
            if (p.first == 0) break;
            result.append(p.first, p.second);
        }
        
        return result;
    }
};