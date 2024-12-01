class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        for(int i=0; i< arr.size(); i++){
            int target = arr[i] * 2;
            if(target < 0){
                auto found = lower_bound(arr.begin(), arr.begin()+i+1, target);
                if(found != arr.end() && target == *found ) return true;
            }
            else{
                auto found = lower_bound(arr.begin()+i+1, arr.end(), target);
                if(found != arr.end() && target == *found ) return true;
            }
        }
        return false;
    }
};