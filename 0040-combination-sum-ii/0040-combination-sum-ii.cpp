class Solution {
public:
    void findcombination(int ind, vector<int> &arr, int target, vector<vector<int>>&ans, vector<int>&ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i=ind; i<arr.size(); i++){
            if(i > ind && arr[i] == arr[i-1]) continue;

            if(arr[i] > target) break;

            ds.push_back(arr[i]);
            findcombination(i+1, arr, target - arr[i], ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findcombination(0, candidates, target, ans, ds);
        return ans;
    }
};