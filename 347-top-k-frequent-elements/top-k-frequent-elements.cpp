class Solution {
public:
    struct cmp {
        bool operator()(pair<int,int>& a, pair<int,int>& b) {
            return a.first > b.first;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        unordered_map<int,int> mp;
        vector<int> res;

        for(int num : nums)
            mp[num]++;

        for(auto i : mp) {

            int element = i.first;
            int frequency = i.second;

            pair<int,int> f = {frequency, element};

            if(pq.size() < k) {
                pq.push(f);
            }
            else if(f.first > pq.top().first) {
                pq.pop();
                pq.push(f);
            }
        }

        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};