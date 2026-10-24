class Solution {
public:
    void findCombination(int index, vector<int>&arr, int target, vector<vector<int>> &ans, vector<int> &current){
        if(index == arr.size()){
            if(target == 0 ){
                ans.push_back(current);
            }
            return;
        }

        if(arr[index] <= target){
            current.push_back(arr[index]);
            findCombination(index, arr, target-arr[index], ans, current);
            current.pop_back();
        }
        findCombination(index + 1, arr, target, ans, current);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        findCombination(0, candidates, target, ans, current);
        return ans;
    }
};