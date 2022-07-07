#include<iostream>
using namespace std;

int min(int i,int r){
    if(i>r){
        return r;
    }
    return i;
}

int main(){
    int n,r;
    cout<<"Enter the value of the n and r\n";
    cin>>n>>r;
    int c[n+1][r+1];
    int i,j;
    for(i=0;i<=n;i++){
        for(j=0;j<=min(i,r);j++){
            if(j==0 || j==i){
                c[i][j]=1;
            }
            else{
                c[i][j]=c[i-1][j]+c[i-1][j-1];
            }
        }
    }
    cout<<"The combination is:- "<<c[n][r]<<"\n";
    for(i=0;i<=n;i++){
        for(j=0;j<=min(i,r);j++){
            cout<<c[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}
