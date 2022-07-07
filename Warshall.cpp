#include<iostream>
using namespace std;

int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

int main(){
    int n,i,j;
    cout<<"Enter the number of the vertices\n";
    cin>>n;
    cout<<"Enter the adjanceny matrix\n";
    int a[n+1][n+1];
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int k;
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                a[i][j]=max(a[i][j],a[i][k]&&a[k][j]);
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
