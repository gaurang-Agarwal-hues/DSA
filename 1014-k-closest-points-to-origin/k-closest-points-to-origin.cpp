class Solution {
public:

    int dist(vector<int>& a) {
        return a[0] * a[0] + a[1] * a[1];
    }

    struct cmp {
        bool operator()(pair<int, vector<int>>& a,
                        pair<int, vector<int>>& b) {
            return a.first < b.first;  
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, vector<int>>,
                       vector<pair<int, vector<int>>>,
                       cmp> pq;

        for (auto &point : points) {

            int distance = dist(point);

            pair<int, vector<int>> p = {distance, point};

            if (pq.size() < k) {
                pq.push(p);
            }
            else if (distance < pq.top().first) {
                pq.pop();
                pq.push(p);
            }
        }

        vector<vector<int>> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};