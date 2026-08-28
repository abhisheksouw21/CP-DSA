class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n=s.size();
        vector<int>f(26,0);
        for(char c: s) f[c-'a']++;
        int ocnt=0;
        int midChar=0;
        vector<int>halfFreq(26,0);
        for(int i=0;i<26;++i){
            if(f[i]%2!=0){
                ocnt++;
                midChar=i+'a';
            }
            halfFreq[i]=f[i]/2;
        }
        if(ocnt>1) return "";
        int m = n / 2;
        string tLeft = target.substr(0, m);
        bool canMatchExact = true;
        vector<int> tFreq(26, 0);
        for (char c : tLeft) tFreq[c - 'a']++;
        
        for (int i = 0; i < 26; ++i) {
            if (tFreq[i] > halfFreq[i]) {
                canMatchExact = false;
                break;
            }
        }

        if (canMatchExact) {
            string p = tLeft;
            if (n % 2 != 0) p += midChar;
            string rev = tLeft;
            reverse(rev.begin(), rev.end());
            p += rev;
            if (p > target) return p;
        }
        for (int i = m - 1; i >= 0; --i) {
            vector<int> avail = halfFreq;
            bool canFormPrefix = true;
            
            for (int j = 0; j < i; ++j) {
                if (--avail[tLeft[j] - 'a'] < 0) {
                    canFormPrefix = false;
                    break;
                }
            }

            if (!canFormPrefix) continue;

            char nextChar = 0;
            for (char c = tLeft[i] + 1; c <= 'z'; ++c) {
                if (avail[c - 'a'] > 0) {
                    nextChar = c;
                    break;
                }
            }

            if (nextChar != 0) {
                string h = tLeft.substr(0, i);
                h += nextChar;
                avail[nextChar - 'a']--;

                for (int c = 0; c < 26; ++c) {
                    h += string(avail[c], c + 'a');
                }

                string p = h;
                if (n % 2 != 0) p += midChar;
                string rev = h;
                reverse(rev.begin(), rev.end());
                p += rev;
                return p;
            }
        }

        return "";
    }
};