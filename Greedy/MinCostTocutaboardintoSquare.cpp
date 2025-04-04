/*Problem 1 Minimum Cost to cut a board into squares.

A board of length M and width N is given. The task 
is to break this board into MN squares such that 
cost of breaking is minimum. The cutting cost for 
each edge will be given for the board in two arrays 
X[] and Y[]. In short, you need to choose such a 
sequence of cutting such that cost is minimized. 
Return the minimized cost.

Input: M=6. N=4 X[] = {2, 1, 3, 1, 4) YD = {4, 1, 2)

Output: 42*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int mincostToBreakGrid(int m,int n,vector<ll> &x,vector<ll> &y){
    sort(x.begin(),y.end(),cmp);
    sort(y.begin(),y.end(),cmp);
    int h=1;
    int v=1;
    int i=0;
    int j=0;
    int cost=0;
    while(i<x.size() && j<y.size()){
        if(x[i]>y[j]){
           cost=cost+x[i]*v;
           h++;
           i++;
        }
        else {
           cost=cost+y[i]*h;
           v++;
           j++;
        }
    }
    while(i<x.size()){
        cost=cost+x[i]*v;
           h++;
           i++;
    }
    while(j<y.size()){
        cost=cost+y[i]*h;
        v++;
        j++;
    }
return cost;
}
int main(){
    int m;
    int n;
    cin>>m>>n;
    vector<ll> x(m-1);
    vector<ll> y(n-1);
    for(int i=0;i<m-1;i++){
        cin>>x[i];
    }
    for(int j=0;j<n-1;j++){
        cin>>y[j];
    }
    int ans=mincostToBreakGrid(m,n,x,y);
    cout<<ans<<endl;
    return 0;
}