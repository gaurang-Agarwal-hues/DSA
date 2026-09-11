class Solution {
public: void recursion(int index,vector<int>&ds,vector<vector<int>>&ans,int target,vector<int>&arr){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i =index;i<arr.size();i++){
        if(i>index && arr[i]==arr[i-1]) continue;
        if(arr[i]>target) break;
        ds.push_back(arr[i]);
        recursion(i+1,ds,ans,target-arr[i],arr);
        ds.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>data;
        sort(candidates.begin(),candidates.end());
        recursion(0,data,ans,target,candidates);
        return ans;
    }
};