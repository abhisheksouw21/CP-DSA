class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        string op = "+-/*";
        
        for (string& s : tokens) {
            
            if (s.size() == 1 && op.find(s[0]) != string::npos) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                if (s == "+") st.push(a + b);
                else if (s == "-") st.push(a - b);
                else if (s == "*") st.push(a * b);
                else if (s == "/") st.push(a / b);
            } 
            else {
              
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};