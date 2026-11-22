class Solution {
public:
    int solve(vector<int> &nums, int left, int right){
        if(left == right)
            return nums[left];

        int pickleft = nums[left] - solve(nums, left+1, right);

        int pickright = nums[right] - solve(nums, left, right-1);

        return max(pickleft, pickright);
    }
    bool predictTheWinner(vector<int>& nums) {
       int diff = solve(nums, 0, nums.size()-1); //nums, left, right

       return diff >=0;
    }
};