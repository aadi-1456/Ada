#include<iostream>
using namespace std;

int mindistance(int *dist,int *s,int n){
    int min=999999;
    int min_index;
    for(int i=0;i<n;i++){
        if(s[i]==0 && dist[i]<min){
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}

int main(){
    int n;
    cout<<"Enter the number of vertices\n";
    cin>>n;
    cout<<"Enter the elements of the matrix\nEnter 999 in case of infinity\n";
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int k;
    cout<<"Enter the source vertex\n";
    cin>>k;
    k=k-1;
    int d[n],s[n];
    for(int i=0;i<n;i++){
        d[i]=a[k][i];
        s[i]=0;
    }
    for(int i=0;i<n;i++){
        cout<<d[i]<<" ";
    }cout<<"\n";
    s[k]=1;
    for(int j=1;j<n;j++){
        int u=mindistance(d,s,n);
        s[u]=1;
        for(int i=0;i<n;i++){
            if(s[i]!=1 && ( (d[u] + a[u][i]) < d[i]) ){
                d[i]=d[u]+a[u][i];
            }
        }
    }
    cout<<"VERTEX\tDESTINATION\tCOST\n";
    for(int i=0;i<n;i++){
        cout<<k+1<<"\t\t"<<i+1<<"\t\t"<<d[i]<<"\n";
    }
    
    return 0;
}
