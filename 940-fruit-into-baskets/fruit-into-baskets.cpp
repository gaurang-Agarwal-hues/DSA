class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int high = 0;
        int low= 0;
        int n = fruits.size();
        int res = 0;
        unordered_map<int, int>m;
        while(high<n){
            m[fruits[high]]++;
            while(m.size()>2){
                m[fruits[low]]--;
                low++;
                if (m[fruits[low-1]]==0){
                    m.erase(fruits[low-1]);
                }
            } if (m.size()<=2){
                int len = high - low+1;
                res = max(res,len);
            }
            high++;
        }
        return res;
    }
};