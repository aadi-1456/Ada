#include<iostream>
using namespace std;


int main(){
    int n,i,j;
    cout<<"Enter the number of the items\n";
    cin>>n;
    int w[n+1],p[n+1];
    cout<<"Enter the value of the weight of the items\n";
    for(i=1;i<=n;i++){
        cin>>w[i];
    }
    cout<<"Enter the value of the profit of the items\n";
    for(i=1;i<=n;i++){
        cin>>p[i];
    }
    int cp;
    cout<<"Enter the capacity of the item\n";
    cin>>cp;
    int kp[n+1][cp+1];
    for(i=0;i<=n;i++){
        kp[i][0]=0;
    }
    for(i=0;i<=cp;i++){
        kp[0][i]=0;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=cp;j++){
            if(w[i]>j){
                kp[i][j]=kp[i-1][j];
            }
            else{
                kp[i][j]=max(kp[i-1][j],p[i]+kp[i-1][j-w[i]]);
            }
        }
    }
    cout<<"The Table is :\n";
    for(i=0;i<=n;i++){
        for(j=0;j<=cp;j++){
            cout<<kp[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"The max profit : "<<kp[n][cp];
    cout<<"\n"<<"The items selected : ";
    j=cp;
    for(i=n;i>0;i--){
        if(kp[i][j]!=kp[i-1][j]){
            cout<<"item "<<i;
            j=j-w[i];
        }
        cout<<" ";
    }
}
