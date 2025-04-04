/*Given an array of meeting time intervals where
 intervals[i]- [start, end), determine if a 
 person could attend all meetings.

Example 1:

Input: intervals [[0,30], [5,10], [15,2011

Output: false

Example 2:

Input: intervals 117,10),(2,4))

Output: true*/
#include<bits/stdc++.h>
using namsespace std;
class Solution{
public:
    bool minMeetingRooms(vector<vector<int>>& intervals){
        if(interval.size()==0) return true;
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
return ans==1;
    }
};
int main(){

    return 0;
}