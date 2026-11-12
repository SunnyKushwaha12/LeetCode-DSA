class Solution {
public:
    vector<string> ans;

    void solve(string s, int index){
        if(index == s.size()){
            ans.push_back(s);;
            return;
        }

        if(isdigit(s[index]))
            solve(s, index+1);
        
        else{
            char original  = s[index];

            // to lowercase
            s[index] = tolower(original);
            solve(s, index+1);

            // to uppercase

            s[index] = toupper(original);
            solve(s, index+1);

            s[index] = original;
        }
    }
    vector<string> letterCasePermutation(string s) {
        solve(s, 0);
        return ans;
    }
};