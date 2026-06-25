class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0;
        int high =0;
        int n = nums.size();
        vector<int>f(2,0);
        int res = 0;
        while (high<n){
            f[nums[high]]++;
            while(f[0]>k){
                f[nums[low]]--;
                low++;
                }
            int len = high-low+1;
            res= max(res,len);
            high++;
        }
        return res;
    }
};