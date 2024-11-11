class Solution{
    vector<bool> SieveOfEratosthenes(int n){
        vector<bool> prime(n + 1, true);

        for (int p = 2; p * p <= n; p++){
            if (prime[p]){
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        return prime;
    }
    public:
        bool primeSubOperation(vector<int> &nums) {
            int n = nums.size();
            // cout<<n<< " ";
            vector<bool> prime = SieveOfEratosthenes(1010);
            for(int i= n-2; i>=0; i--){
                int diff = nums[i] - nums[i+1];
                // cout<<nums[i]<<" "<<nums[i+1]<<" \n";
                if(diff == 0) diff++;
                diff++;
                
                for(int j = diff; diff >=0 && j < 1010; j++){
                    // cout<<j<<" "<< prime[j]<<" 
                    if(prime[j]){
                        nums[i] -= j;
                        // cout<<nums[i]<<" ";
                        if(nums[i] <= 0) return false;
                        break;
                    }
                }

            }
            return true;
        }
};