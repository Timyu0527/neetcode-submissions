class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        vector<char> stk;
        for(int i = 0; i < n; ++i) {
            char c = s[i];
            if(stk.empty() && (c == ')' || c == ']' || c == '}')) {
                return false;
            }
            if(stk.empty() && (c == '(' || c == '[' || c == '{')) {
                stk.push_back(c);
            } else if(c == '(' || c == '[' || c == '{') {
                stk.push_back(c);
            } else if(c == ')' && stk.back() == '(') {
                stk.pop_back();
            } else if(c == ']' && stk.back() == '[') {
                stk.pop_back();
            } else if(c == '}' && stk.back() == '{') {
                stk.pop_back();
            } else {
                return false;
            }
        }
        return stk.empty();
    }
};
