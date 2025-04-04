class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<char,int>>pq;
        for(auto el: mp){
            pq.push(el);
        }
        string result="";
        while(!pq.empty()){
            auto largest=pq.top();
            pq.pop();
            int len=min(repeatLimit,largest.second);
            for(int i=0;i<len;i++){
                result+=largest.first;
            }
            pair<char,int> secondlargest;
            if(largest.second-len>0){
                if(!pq.empty()){
                    secondlargest=pq.top();
                    pq.pop();
                    result+=secondlargest.first;
                }
                else{
                    return result;
                }
                if(secondlargest.second-1>0) pq.push({secondlargest.first,secondlargest.second-1});
                pq.push({largest.first,largest.second-len});
            }
        }
        return result;
    }
};