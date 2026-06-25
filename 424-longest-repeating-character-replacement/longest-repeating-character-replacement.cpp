class Solution {
public:
 int mxcnt(vector<int>&arr){
            int maxcnt=INT_MIN;
            for(int i =0;i<256;i++){
              if (arr[i]>maxcnt){
                maxcnt = arr[i];
              }}
        return maxcnt;}
        
    int characterReplacement(string s, int k) {
       
         int low = 0;
         int high = 0;
         int res = 0;
         vector<int>f(256,0);
         int n = s.size();
         while(high<n){
            f[s[high]]++;
            int len = high-low+1;
            int maxcnt=mxcnt(f);
            int diff = len - maxcnt;
            while (diff>k){
                f[s[low]]--;
                low++;
                maxcnt=mxcnt(f);
                 len = high- low +1;
                 diff = len - maxcnt;
            }
            len = high-low+1;
            res= max (res,len);
            high ++;
         } 
         return res;
    }
};