class Solution {
public: 
    vector<string> ans;
    
    void solve(string s, int index, int count, string current){
        if(count == 4){
            if(index == s.size()){
                ans.push_back(current);
            }
            return;
        }

        // try all possible len 1, 2, 3
        for(int len=1; len <= 3; len++){

            if(index + len > s.size())
                break;
            
            string part = s.substr(index, len);

            // leading zero check
            if(part.size() > 1 && part[0] == '0')
                break;
            
            //range
            if(stoi(part) > 255)
                break;

            if(count == 0)
                solve(s, index + len, count + 1, part);
            
            else{
                solve(s, index + len , count + 1, current + "." + part);
            }
                
        }
    }
    vector<string> restoreIpAddresses(string s) {
        solve(s, 0, 0, "");
        return ans;
    }
};