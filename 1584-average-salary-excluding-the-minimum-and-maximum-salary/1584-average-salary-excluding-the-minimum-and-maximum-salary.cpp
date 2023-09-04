class Solution {
public:
    double average(vector<int>& salary) {
        int mini = INT_MAX, maxi = 0;
        double sum =0.0;
        for(int i: salary){
            mini = min(mini, i);
            maxi = max(maxi, i);
            sum += i;
        }
        sum = sum -mini - maxi;
        return sum/(salary.size() -2);
    }
};