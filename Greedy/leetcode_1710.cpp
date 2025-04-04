bool cmp(vector<int>& v1,vector<int> &v2){
         int r1=v1[1];
         int r2=v2[1];
         return r1>r2; 
}
class Solution {
public:

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int result=0;
        int n=boxTypes.size();
        for(int i=0;i<boxTypes.size();i++){
        if(boxTypes[i][0]<=truckSize){
            result+=boxTypes[i][0]*boxTypes[i][1];
            truckSize-=boxTypes[i][0];
        }
        else{
            result+=truckSize*boxTypes[i][1];
            truckSize=0;
        }
        if(truckSize==0) break;
    }
         return result;
    }
};