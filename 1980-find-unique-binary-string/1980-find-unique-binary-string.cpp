class Solution {
public:
    string ans = "";
    unordered_set<string> st;

    bool solve(int index, string &curr, int n) {

        // Base case
        if (index == n) {
            if (st.find(curr) == st.end()) {
                ans = curr;
                return true;
            }
            return false;
        }

        // Choice 1: Add 0
        curr.push_back('0');

        if (solve(index + 1, curr, n))
            return true;

        curr.pop_back();  // Backtrack

        // Choice 2: Add 1
        curr.push_back('1');

        if (solve(index + 1, curr, n))
            return true;

        curr.pop_back();  // Backtrack

        return false;
    }

    string findDifferentBinaryString(vector<string>& nums) {

        int n = nums.size();

        for (auto &s : nums) {
            st.insert(s);
        }

        string curr = "";

        solve(0, curr, n);

        return ans;
    }
};