class Solution {
public:
    void solve(int index, vector<vector<int>> &ans, vector<int> &nums, vector<int> &current){
        if(index == nums.size()){
            ans.push_back(current);
            return;
        }

        // Pick the element
        current.push_back(nums[index]);
        solve(index+1, ans, nums, current);

        // pop the element
        current.pop_back();
        solve(index + 1, ans, nums, current);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(0, ans, nums, current);
        return ans;
    }
};