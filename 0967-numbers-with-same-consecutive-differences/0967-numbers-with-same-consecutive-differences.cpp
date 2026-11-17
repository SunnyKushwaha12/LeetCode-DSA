class Solution {
public:
    void solve(int curr, int len, int n, int k, vector<int>&ans){

        if(len == n){
            ans.push_back(curr);
            return;
        }

        int last = curr % 10;

        // choice
        int d1 =  last + k;

        if(d1 <= 9){
            solve(curr * 10 + d1, len + 1, n, k, ans);
        }

        // choice 2
        int d2 = last - k;

        if(d2 >= 0 && k !=0)
            solve(curr * 10 + d2, len + 1, n, k, ans);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;

        for(int i=1; i<=9; i++){
            solve(i, 1, n, k, ans);
        }
        return ans;
    }
};