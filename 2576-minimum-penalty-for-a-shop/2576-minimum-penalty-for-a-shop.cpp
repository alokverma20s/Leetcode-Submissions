class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int cntN = 0, cntY = 0;
        for(int i=0; i< n; i++){
            if(customers[i] == 'N')
                cntN++;
            else
                cntY++;
        }

        int mini = n, index = -1;
        int N =0, Y = cntY; 
        for(int i=0; i<n ;i++){

            if(mini > Y+N){
                mini = Y+N;
                index = i;
            }
            if(customers[i] == 'N')
                N++;
            else{
                Y--;
            }
        }
        if(mini > Y+N){
            mini = Y+N;
            index = n;
        }

        return index;
    }
};