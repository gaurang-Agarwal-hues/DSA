class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int low = 0;
        int cnt = 0;
        int oddCount = 0;

        for (int high = 0; high < nums.size(); high++) {

            if (nums[high] % 2)
                oddCount++;

            while (oddCount > k) {
                if (nums[low] % 2)
                    oddCount--;
                low++;
            }

            cnt += (high - low + 1);
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};