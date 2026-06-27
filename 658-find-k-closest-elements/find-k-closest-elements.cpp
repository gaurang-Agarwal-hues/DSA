class Solution {
public: 
int distance(int a,int b){
    int x = abs(a-b);
    return x;
}
struct cmp {
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        if (a.first==b.first){
            return a.second<b.second;
        }
        return a.first<b.first;
    }
};

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        int n = arr.size();
        for (int i =0;i<n;i++){
            int dist = distance(arr[i],x);
            pair<int,int>f= {dist,arr[i]};
            if(pq.size()<k){
                pq.push(f);
            }
          else if (f.first<pq.top().first){
            pq.pop();
            pq.push(f);
           }
        else   if (f.first==pq.top().first && f.second<pq.top().second){
            pq.pop();
            pq.push(f);
           }
        }
        vector<int>res;
      while (!pq.empty()) {
    res.push_back(pq.top().second);
    pq.pop();
}

sort(res.begin(), res.end());

return res;
    }
};