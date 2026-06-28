class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        string ans="";
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        while(pq.size()>1)
        {
            char ch=pq.top().second;
            int fre1=pq.top().first;
            pq.pop();
            char nt=pq.top().second;
            int fre2=pq.top().first;
            pq.pop();
            ans+=ch;
            ans+=nt;
            if(fre1-1!=0)
            pq.push({fre1-1,ch});
            if(fre2-1!=0)
            pq.push({fre2-1,nt}); 
        }
        if(pq.size()==1)
        {
            if(pq.top().first>1)return "";
            else ans+=pq.top().second;
        }
        return ans;

    }
};