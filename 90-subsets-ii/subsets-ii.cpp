class Solution {
public: void subset(int ind,vector<int>&ds,vector<vector<int>>&answer,vector<int>&nums){
    answer.push_back(ds);
    for(int i=ind;i<nums.size();i++){
        if(i != ind && nums[i]==nums[i-1]) continue;
        ds.push_back(nums[i]);
        subset(i+1,ds,answer,nums);
        ds.pop_back();
    }
    return;
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>answer;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        subset(0,ds,answer,nums);
        return answer;
    }
};