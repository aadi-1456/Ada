#include<iostream>
using namespace std;

int min(int a,int b){
    if(a>b){
        return b;
    }
    return a;
}

int main(){
    int k,n,i,j;
    cout<<"Enter the number of the vertices\n";
    cin>>n;
    int a[n+1][n+1];
    cout<<"Enter the adjanceny matrix\n";
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    cout<<"The shortest path obtained :\n";
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
