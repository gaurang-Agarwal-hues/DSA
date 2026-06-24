class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low= 0;
        int high =0;
        int n = s.size();
        int res = 0;
        unordered_map<char,int>m;
        while (high<n){
        m[s[high]]++;
        int len = high-low+1;
        while (m.size()<len){
            m[s[low]]--;
            if(m[s[low]]==0) {
                m.erase(s[low]);
            }
            low++;
            len = high-low+1;
        }
        len = high-low+1;
        res = max(res,len);
        high++;
        } return res;
    }
};