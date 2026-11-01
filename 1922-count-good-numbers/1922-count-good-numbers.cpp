class Solution {
public:
    long long mod = 1e9 + 7;

    long long power(long long x, long long n){
        if(n==0) return 1;

        long long half = power(x, n/2);

        long long  ans = (half * half) % mod;

        if(n % 2 == 1){
            ans = (ans * x) % mod;
        }

        return ans;
    }
    int countGoodNumbers(long long n) {
       long long even =  (n+1) /2;
       long long odd =  n /2;

       long long a = power(5, even); // 5 even digits: 0, 2, 4, 6, 8
       long long b = power(4, odd);  // 4 prime digits: 2, 3, 5, 7

       return (a * b) % mod;
    }
};