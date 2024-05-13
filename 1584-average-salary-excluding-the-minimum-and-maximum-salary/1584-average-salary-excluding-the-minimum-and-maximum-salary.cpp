#define fl(i, l, r) for(int i=(l); i< r; i++)
class Solution {
public:
    double average(vector<int>& salary) {
        double totalSalary = 0;
        int minSal = INT_MAX;
        int maxSal = 0;

        int n = salary.size();
        fl(i, 0, n){
            minSal = min(minSal, salary[i]);
            maxSal = max(maxSal, salary[i]);
            totalSalary += salary[i];
        }
        totalSalary -=(minSal + maxSal);
        return totalSalary/(n-2);

    }
};