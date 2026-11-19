class Solution {
public:
    int solve(int n, int head, int step, bool left){
        if(n == 1)
            return head;
        
        if(left || n % 2 == 1)
            head += step;
        
        step *=2;
        n = n /2;

        return solve(n, head, step, !left);
    }
    int lastRemaining(int n) {
        return solve(n, 1, 1, true);
    }
};