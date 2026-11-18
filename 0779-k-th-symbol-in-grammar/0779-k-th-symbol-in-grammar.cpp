// class Solution {
// public:
//     int kthGrammar(int n, int k) {
//         string row = "0";

//         for(int i=2; i<=n; i++){
//             string nextRow = "";

//             for(char ch : row){
//                 if(ch == '0')   
//                     nextRow += "01";
                
//                 else
//                     nextRow += "10";
//             }
//             row = nextRow;
//         }
//         return row[k-1] - '0';
//     }
// };


class Solution {
public:
    int kthGrammar(int n, int k) {

        if(n == 1){
            return 0;
        }

        int mid = pow(2, n-2);

        if(k <= mid)
            return kthGrammar(n-1, k);
        
        return 1 - kthGrammar(n-1, k- mid);
    }
};