class Solution {
public:
    int ladderLength(string s, string e, vector<string>& words) {
        queue<pair<string,int>>q;
       q.push({s,1});
       unordered_set<string>st(words.begin(),words.end());
       st.erase(s);
       while(!q.empty()){
           string word=q.front().first;
           int cnt= q.front().second;
           q.pop();
           if(word==e) return cnt;
           for(int i=0;i<word.size();++i){
               char orginial = word[i];
               for(char ch='a'; ch<='z';ch++){
                   word[i]=ch;
                   if(st.find(word)!=st.end()){
                       st.erase(word);
                       q.push({word,cnt+1});
                   }
               }
               word[i]=orginial;
           }
       }
       return 0;
        
    }
};