class Solution {
public:
    int minsum(vector<int>& arr) {
        int bestEnding = arr[0];
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            bestEnding = min(arr[i], bestEnding + arr[i]);
            ans = min(ans, bestEnding);
        }

        return ans;
    }

    int maxsum(vector<int>& arr) {
        int bestEnding = arr[0];
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            bestEnding = max(arr[i], bestEnding + arr[i]);
            ans = max(ans, bestEnding);
        }

        return ans;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        return max(abs(maxsum(nums)), abs(minsum(nums)));
    }
};