#include<iostream>
using namespace std;


int main(){
    int i,j,n;
    cout<<"Enter the number of vertices\n";
    cin>>n;
    cout<<"Enter the adjanceny matrix\n";
    int cost[n+1][n+1];
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>cost[i][j];
        }
    }
    int indeg[n+1]={0};
    int flag[n+1]={0};
    for(j=1;j<=n;j++){
        for(i=1;i<=n;i++){
            indeg[j]=indeg[j]+cost[i][j];
        }
    }
    
    cout<<"\nThe topological order is :\n";
    int ne=1;
    while(ne<n){
        for(int k=1;k<=n;k++){
            if(indeg[k]==0 && flag[k]==0){
                cout<<k<<" ";
                flag[k]=1;
                for(i=1;i<=n;i++){
                    if(cost[k][i]==1){
                    indeg[i]--;
                    }
                }
            }
        }
        ne++;
    }
    return 0;
}

