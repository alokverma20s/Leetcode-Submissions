class Solution {
    int ncr(int n, int r){
        if(r==0)
            return 1;
        else if(r==n)
            return 1;
        int m=n;
        if(r>n/2)
            r=n-r;
        long int numrtr=1;
        for(int i=0;i<r;i++){
            numrtr*=m;
            m--;
        }
        long int dnmtr=1,l=r;
        for(int i=0;i<r;i++){
            dnmtr*=l--;
        }
        return (numrtr/dnmtr);
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                temp.push_back(ncr(i,j));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};