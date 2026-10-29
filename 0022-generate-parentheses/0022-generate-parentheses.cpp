class Solution {
public:
    void solve(string s, vector<string>&ans, int open, int close, int n){
        if(s.length() == 2*n ){
            ans.push_back(s);
            return;
        }

        if(open < n)
            solve(s + "(", ans, open+1, close, n);  

        if(close < open)
            solve(s + ")", ans, open, close+1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("", ans, 0,0, n);
        return ans;
    }
};