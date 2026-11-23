class Solution {
public:
    // int solve(vector<int>&piles, int left, int right){
    //     if(left == right)
    //         return piles[left];

    //     int pickleft = piles[left] - solve(piles, left + 1, right);

    //     int pickright = piles[right] - solve(piles, left, right - 1);

    //     return max(pickleft, pickright);
    // }
    bool stoneGame(vector<int>& piles) {
        // int diff = solve(piles, 0, piles.size()-1);
        // return diff > 0;
        return true;
    }
};