class Solution {
    void print(vector<vector<int>> &matrix){
        for(auto i: matrix){
            for(int j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int a, b, c, d;
        for(int i=0 ;i<n/2; i++){
            int j =i;
            for(int k=0; k< n-1-(i*2); k++){
                a = matrix[i][j];
                b = matrix[j][n-i-1];
                c = matrix[n-i-1][n-1-j];
                d = matrix[n-1-j][i];

                matrix[i][j] = d;
                matrix[j][n-i-1] = a;
                matrix[n-i-1][n-1-j] = b;
                matrix[n-1-j][i] = c;
                // print(matrix);
                j++;
            }
        }
    }
};