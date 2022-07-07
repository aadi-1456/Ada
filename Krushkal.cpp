#include<iostream>
using namespace std;

int find(int i,int parent[]){
    return (parent[i]);
}

int main(){
    int i,j,k,n;
    cout<<"Enter the number of vertices\n";
    cin>>n;
    int cost[n+1][n+1];
    cout<<"Enter the cost of adjanceny matrix\n";
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>cost[i][j];
        }
    }
    int parent[n+1];
    for(i=0;i<=n;i++){
        parent[i]=i;
    }
    int ne=1,min,a,b,u,v,mincost=0;
    while(ne<n){
        for(i=1,min=999;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j]<min){
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u,parent);
        v=find(v,parent);
        if(u!=v){
            cout<<"\nEdge "<<(ne++)<<" :("<<a<<","<<b<<") cost :"<<min;
            mincost +=min;
        }
        cost[a][b]=cost[b][a]=999;
    }
    cout<<"\nMinimum cost = "<<mincost;
    return 0;
}
