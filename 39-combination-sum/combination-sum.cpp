class Solution {
public: void recursion(int target,int index,vector<int>&array,vector<vector<int>>&answer,vector<int>&ds) {
    if(index==array.size()){
        if(target==0){
            answer.push_back(ds);
        }
        return;
    }
    if(target>=array[index]){
        ds.push_back(array[index]);
        recursion(target-array[index],index,array,answer,ds);
        ds.pop_back();
        
    }
    recursion(target,index+1,array,answer,ds);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>answer;
        vector<int>ds;
       recursion(target,0,candidates,answer,ds);
       return answer;
    }
};