#include<iostream>
using namespace std;

int main(){
    int n,i,j;
    cout<<"Enter the number of the vertices\n";
    cin>>n;
    cout<<"Enter the adjanceny matrix\n";
    int cost[n+1][n+1];
    int visit[n+1]={0};
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>cost[i][j];
            if(cost[i][j]==0){
                cost[i][j]=999;
            }
        }
    }
    int ne=1,u,v,a,b,mincost=0;
    visit[1]=1;
    int min;
    cout<<"\n";
    while(ne < n){
        for(i=1,min=999;i<=n;i++){
            for(j=1;j<=n;j++){
                if(cost[i][j]<min)
                if(visit[i]!=0){
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }    
        if(visit[u]==0 || visit[v]==0){
            cout<<"\nEdge "<<(ne++)<<":("<<a<<","<<b<<") cost :"<<min;
            mincost +=min;
            visit[b]=1;
        }
        cost[a][b]=cost[b][a]=999;
            
        
    }
    cout<<"\nMinimum cost = "<<mincost;
    return 0;
}
