#include<bits/stdc++.h>
using namespace std;
int min_product_subset(vector<int> &arr){
    int cn=0,cp=0,co=0;
    int pos=1;
    int neg=1;
    int largeneg=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0) {cp++;
         pos*=arr[i];
         }
        if(arr[i]==0) co++;
        if(arr[i]<0) {
            cn++;
             neg*=arr[i];
              largeneg=max(largeneg,arr[i]);}
    }
    if(cn==0){
        if(co>0) return 0;
        else{
            auto it=min_element(arr.begin(),arr.end());
            return *it;
        }
    }
    else{
        if(cn%2==0){
           //even
           return (neg/largeneg)*pos;
        }
        else{
            //odd
            return pos*neg;
        }
    }
}
int main(){
    vector<int> arr={11,2,3};
    cout<<min_product_subset(arr)<<endl;
    return 0;
}
