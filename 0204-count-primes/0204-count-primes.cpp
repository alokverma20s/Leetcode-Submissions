class Solution {
public:
    int countPrimes(int n) {
        int cnt=0;
        // n--;
        vector<bool> prime(n+1,true);
        prime[0]=prime[1]=false;
        for(long i=2;i*i <=n;i++){
            if(prime[i]){
                for(long j=i*i;j<=n;j=j+i)
                    prime[j]=false;
            }
        }
        prime.pop_back();
        for(bool i: prime) if(i) cnt++;
        return cnt;
    }
};