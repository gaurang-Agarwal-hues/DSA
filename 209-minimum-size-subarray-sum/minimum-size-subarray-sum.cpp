class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int low=0;
        int high =0;
        int res = INT_MAX;
        int sum = 0;
        int n = arr.size();
        while (high<n){
            sum = sum + arr[high];
            while (sum>=target){
                int len = high-low+1;
                res = min(res,len);
                sum = sum - arr[low];
                low++;
            }
            high++;
        } return res == INT_MAX? 0: res;
    }
};