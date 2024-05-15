class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int k =0;
        int i=0,j=0;
        double sum=0;
        if((m+n)%2){
            while(i<n&&j<m&&(k<=(m+n)/2)){
                if(nums1[i]<nums2[j]){
                    i++;
                    if(k==(m+n)/2)
                        return nums1[i-1];
                }
                else{
                    j++;
                    if(k==(m+n)/2)
                        return nums2[j-1];
                }
                k++;
            }
            while(j<m&&(k<=(m+n)/2)){
                j++;
                
                if(k==(m+n)/2)
                    return nums2[j-1];
                k++;
            }
            while(i<n&&(k<=(m+n)/2)){
                i++;
                
                if(k==(m+n)/2)
                    return nums1[i-1];
                k++;
            }
            
        }
        else{
            while(i<n&&j<m&&(k<=(m+n)/2)){
                if(nums1[i]<nums2[j]){
                    i++;
                    if(k==(m+n)/2||k==((m+n)/2)-1){
                        sum+= nums1[i-1];
                    }
                }
                else{
                    j++;
                    if(k==(m+n)/2||k==((m+n)/2)-1){
                        sum+= nums2[j-1];
                    }
                }
                k++;
            }
            while(j<m&&(k<=(m+n)/2)){
                j++;
                if(k==(m+n)/2||k==((m+n)/2)-1){
                    sum+= nums2[j-1];
                }
                k++;
            }
            while(i<n&&(k<=(m+n)/2)){
                i++;
                
                if(k==(m+n)/2||k==((m+n)/2)-1){
                    sum+= nums1[i-1];
                }
                k++;
            }
        }
        return sum/2.0;
    }
};