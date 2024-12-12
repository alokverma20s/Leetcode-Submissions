class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;

        for(int i: gifts) pq.push(i);

        for(int i =0; i< k; i++){
            if(pq.top() > 1){
                int t = pq.top();
                pq.pop();
                t = sqrt(t);
                pq.push(t);
            }
            else break;
        }

        long long ans = 0;
        while(!pq.empty()){
            // cout<< pq.top()<<" ";
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};