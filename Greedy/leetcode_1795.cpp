#include<bits/stdc++.h>
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
         int neg=0;
        long long sum=0;
        int mini=INT_MAX;
        for(auto row:matrix){
            for(auto x:row){
            mini=min(mini,abs(x));
            if(x<0){
                sum-=x;
                neg++;
            }
            else{
                sum+=x;
            }
        }
        }
        return (neg%2==0)?sum:sum-2*mini;
    }
};