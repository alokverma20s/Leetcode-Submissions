class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int>ans(2);
        vector<float> frac;

        int n = arr.size();
        for(int i=0; i<n; i++){
            for(int j=i; j< n; j++)
                frac.push_back(((float)arr[i]/(float)arr[j]));
        }

        sort(frac.begin(), frac.end());
        float target = frac[k-1];

        for(int i=0; i<n; i++){
            bool found = false;
            for(int j=i; j< n; j++){
                float t = ((float)arr[i]/(float)arr[j]);
                if(t == target){
                    ans = {arr[i], arr[j]};
                    found = true;
                    break;
                }
            }
            if(found)
                break;
        }
        return ans;
    }
};