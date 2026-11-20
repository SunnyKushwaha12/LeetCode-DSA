class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;

        for (int i = 0; i < expression.size(); i++) {
            char op = expression[i];

            if (op == '+' || op == '-' || op == '*') {
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                vector<int> leftAns = diffWaysToCompute(left);
                vector<int> rightAns = diffWaysToCompute(right);

                for (int a : leftAns) {
                    for (int b : rightAns) {
                        if (op == '+')
                            ans.push_back(a + b);
                        else if (op == '-')
                            ans.push_back(a - b);
                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }

        // If no operator exists, expression is just a number
        if (ans.empty()) {
            ans.push_back(stoi(expression));
        }

        return ans;
    }
};