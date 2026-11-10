class Solution {
public:
    vector<string> ans;
    void solve(int idx, string num, int target, string path, long long value, long long prev){
        // base case
        if(idx == num.size()){
            if(value == target){
                ans.push_back(path);
            }
            return;
        }
        // try diff, number that starts from thr index
        for(int i=idx; i<num.size(); i++){

            // avoid leading zero
            if(i > idx && num[idx] == '0')
                break;
            
            string str = num.substr(idx, i-idx+1);
            long long curr = stoll(str);

            // when current no. if the first number

            if(idx == 0){
                solve(i+1, num, target, str, curr, curr);
            }
            else{
                // add
                solve(i+1, num, target, path + "+" +str, value + curr, curr );
                // sub
                solve(i+1, num, target, path + "-" + str, value - curr, - curr);
                // multi
                solve(i+1, num, target, path + "*" + str, value - prev + prev * curr, prev * curr);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        ans.clear();

        solve(0, num, target, "", 0, 0);
        return ans;
    }
};