class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
       vector<string>ans;
       istringstream ss(text);
       string f,s,w;
       while(ss>>w){
        if(f==first && s==second) ans.push_back(w);
        f=s;
        s=w;
       } 
       return ans;
    }
};