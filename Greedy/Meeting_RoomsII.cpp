/*Given an array of meeting time 
intervals intervals where 
intervals[i] [starti, endi], return the
minimum number of conference rooms 
required.

Example 1:

Input: intervals = [[0,30], [5,10], [15,20]]

Output: 2

Example 2:

Input: intervals = [[7,10],[2,4]]

Output: 1*/
#include<bits/stdc++.h>
using namsespace std;
class Solution{
public:
    int minMeetingRooms(vector<vector<int>>& intervals){
       int n=intervals.size();
       vector<int>start(n);
       vector<int>finish(n);
       for(int i=0;i<n;i++){
        start[i]=vector[i][0];
        finish[i]=vector[i][1];
       }
       sort(start.begin(),start.end());
       sort(finish.begin(),finish.end());
       int i=0;
       int j=0;
       int room=0;
       int ans=INT_MIN;
       while(i<start.size()&&j<finish.size()){
        if(start[i]<finish[i]){
            room++;
            ans=max(ans,room);
            i++;
         
        }
        else if(start[i]==finish[i]){
             j++;
             i++;
        }
        else{
            room--;
            j++;
        }
        ans=max(ans,room);
       }
return ans;
    }
};
int main(){

    return 0;
}