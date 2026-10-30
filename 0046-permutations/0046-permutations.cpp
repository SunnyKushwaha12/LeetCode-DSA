class Solution {
public:
    // approach 1
    // void func(vector<int>&ds, vector<int> &nums, vector<vector<int>>&ans,  vector<int>&freq){
    //     if(ds.size() == nums.size()){
    //         ans.push_back(ds);
    //         return;
    //     }

    //     for(int i=0; i<nums.size(); i++){
    //         if(!freq[i]){
    //             ds.push_back(nums[i]);
    //             freq[i] = 1;
    //             func(ds, nums, ans, freq);
    //             freq[i] = 0;
    //             ds.pop_back();
    //         }
    //     }
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     vector<int> ds;
    //     vector<int> freq(nums.size(), 0);
    //     for(int i=0; i<nums.size(); i++)
    //         freq[i]=0;

    //     func(ds, nums, ans, freq);
    //     return ans;
    // }



    // approach 2
    void findPermute(int ind, vector<int> &arr, vector<vector<int>>&ans){
        if(ind == arr.size()){
            ans.push_back(arr);
            return;
        }

        for(int i=ind; i<arr.size(); i++){
            swap(arr[ind], arr[i]);
            findPermute(ind+1, arr, ans);
            swap(arr[ind], arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        findPermute(0, nums, ans);
        return ans;
    }


};