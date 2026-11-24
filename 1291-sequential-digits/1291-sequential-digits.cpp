class Solution {
public:
    vector<int> ans;

    void solve(int current, int nextDigit, int low, int high){
        if(current > high)
            return;
        
        if(current >= low)
            ans.push_back(current);
        
        if(nextDigit > 9)
            return;
        
        int next = current * 10 + nextDigit;

        solve(next, nextDigit + 1, low, high);
        
    }
    vector<int> sequentialDigits(int low, int high) {
        for(int i=1; i<=9; i++){
            solve(i, i+1, low, high);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};