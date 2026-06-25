class Solution {
public: bool correct(vector<int>&a,vector<int>&b){
    for(int i =0;i<255;i++){
        if(b[i]>a[i]) {
            return false;
        }
    } return true;
}
    string minWindow(string s, string t) {
     vector<int>needed(255,0);
       for(char c:t) needed[c]++; 
       vector<int>have(255,0);
       int high =0;
       int low =0;
       int res = INT_MAX;
       int size=0;
       int start=0;
       int n = s.size();
       while (high<n){
        have[s[high]]++;
        while(correct(have,needed)){
            int len = high-low+1;
            if(len<res){
              res=len;
              size=res;
              start=low;
            }
            have[s[low]]--;
            low++;
        }
        high++;
       }
       if (res==INT_MAX) return "";
        return s.substr(start,size);
    }
};