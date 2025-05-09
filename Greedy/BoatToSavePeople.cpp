class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0;
        int j=people.size()-1;
        int boat=0;
        while(i<=j){
            if(people[j]>=limit){
                boat++;
                j--;
            }
            else if(people[i]+people[j]>limit){
                boat++;
                j--;
            }
            else{
                boat++;
                i++;
                j--;
            }
        }
        return boat;
    }
};