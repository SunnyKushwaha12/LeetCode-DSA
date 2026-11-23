class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>&piles, int left, int right){
        if(left == right)
            return piles[left];
        
        if(dp[left][right] != INT_MIN)
            return dp[left][right];

        int pickleft = piles[left] - solve(piles, left + 1, right);

        int pickright = piles[right] - solve(piles, left, right - 1);

        return dp[left][right] =  max(pickleft, pickright);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n, INT_MIN));
        int diff = solve(piles, 0, n-1);
        return diff > 0;
    }
};