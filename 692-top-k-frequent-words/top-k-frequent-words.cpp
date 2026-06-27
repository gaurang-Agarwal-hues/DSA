class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second < b.second;  
            }
            return a.first > b.first;   
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> mp;

        for (string word : words) {
            mp[word]++;
        }

        priority_queue<pair<int, string>,
                       vector<pair<int, string>>,
                       cmp> pq;

        for (auto it : mp) {

            pair<int, string> p = {it.second, it.first};

            if (pq.size() < k) {
                pq.push(p);
            }
            else {
                if (p.first > pq.top().first ||
                   (p.first == pq.top().first &&
                    p.second < pq.top().second)) {

                    pq.pop();
                    pq.push(p);
                }
            }
        }

        vector<string> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};