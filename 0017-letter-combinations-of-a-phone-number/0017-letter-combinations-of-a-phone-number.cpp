class Solution {
public:
    vector<string> ans;
    map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void solve(int index, string digits, string path){
        if(index == digits.size()){
            ans.push_back(path);
            return;
        }   

        string letters = mp[digits[index]];
 
        for(int i=0; i<letters.size(); i++){
            path.push_back(letters[i]);
            solve(index+1, digits, path);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        solve(0, digits, "");
        return ans;
    }
};