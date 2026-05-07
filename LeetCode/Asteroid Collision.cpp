class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        for(int i : asteroids){
            if(i<0 && !s.empty() && s.top()>0){
                bool flag=true;
                while(!s.empty()&& s.top()>0){
                    if(abs(i)>s.top()){
                        s.pop();
                    }
                    else if(abs(i)<s.top()){
                       flag=false;
                        break;
                    }
                    else{
                        s.pop();
                        flag=false;
                        break;
                    }
                }
                if(flag)s.push(i);
            }
            else{
                s.push(i);
            }

        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};