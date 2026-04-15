class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>v(26,0);
       for(int i = 0; i < s.size(); i++){
    v[s[i] - 'a'] = i;
}
        int pe=0,ps=0;
        vector<int>ans;
        for(int i=0;i<s.size();++i){
         pe = max(pe,v[s[i]-'a']);
         if(i==pe){
            ans.push_back(i-ps+1);
            ps=i+1;
         }
        }
        return ans;
    }
};