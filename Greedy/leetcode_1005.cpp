class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        while(k--){
            int x=pq.top();
            pq.pop();
            x=0-x;
            pq.push(x);
        }
        int sum=0;
        while(pq.size()>0){
           sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};