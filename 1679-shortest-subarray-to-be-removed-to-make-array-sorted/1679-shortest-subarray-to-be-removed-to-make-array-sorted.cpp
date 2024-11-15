class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int prefix = 0;
        int suffix = n - 1;

        // Find the longest non-decreasing prefix
        while (prefix < n - 1 && arr[prefix] <= arr[prefix + 1]) {
            prefix++;
        }

        // If the entire array is non-decreasing, no need to remove any subarray
        if (prefix == n - 1) return 0;

        // Find the longest non-decreasing suffix
        while (suffix > 0 && arr[suffix] >= arr[suffix - 1]) {
            suffix--;
        }

        // Calculate the minimum length of the subarray to be removed
        int minLength = min(n - prefix - 1, suffix);

        // Check if we can merge the prefix and suffix
        int i = 0, j = suffix;
        while (i <= prefix && j < n) {
            if (arr[i] <= arr[j]) {
                minLength = min(minLength, j - i - 1);
                i++;
            } else {
                j++;
            }
        }

        return minLength;
    }
};
