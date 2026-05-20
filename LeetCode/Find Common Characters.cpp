
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
       
        vector<int> cnt(26, 100), crrcnt(26);
        vector<string> ans;

        for (int i = 0; i < n; i++) {
          
            fill(crrcnt.begin(), crrcnt.end(), 0);
            
            for (char c : words[i]) {
                crrcnt[c - 'a']++;
            }
            
           
            for (int j = 0; j < 26; j++) {
                cnt[j] = min(cnt[j], crrcnt[j]);
            }
        }
        for (int i = 0; i < 26; i++) {
            while (cnt[i] > 0) {
                ans.push_back(string(1, i + 'a'));
                cnt[i]--;
            }
        }

        return ans;
    }
};