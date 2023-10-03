class Solution {
    int ncr(int n ){
        return (n*(n-1))/2;
    }
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> m;
        for(int i=0; i<nums.size();i++){
            m[nums[i]]++;
        }
        int ans=0;
        for(auto i:m){
            if(i.second!=1){
                ans +=ncr(i.second);
            } 
        }
        return ans;
    }
};