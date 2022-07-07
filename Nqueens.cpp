#include<iostream>
using namespace std;

void print(int **b,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<b[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool possible(int **b,int n,int i,int j){
    int row,col;
    for(row=0;row<n;row++){
        if(b[row][j]==1){
            return false;
        }
    }
    for(col=0;col<n;col++){
        if(b[i][col]==1){
            return false;
        }
    }
    //in this loop we are seeing the upper left part of the n-queens diagonal
    for(row=i,col=j;row>=0&&col>=0;row--,col--){
        if(b[row][col]==1){
            return false;
        }
    }     // This loop is the main condition for the n-queens problem
      // In this we are seeing the upper right part of diagonal
    for(row=i,col=j;row<n&&row>=0&&col>=0&&col<n;row--,col++){     //row<n&&row>=0&&col>=0&&col<n;row--,col++
        if(b[row][col]==1){
            return false;
        }
    }
    return true;
}

void findpossible(int **b,int n,int i,int j){
    if(i==n){
        print(b,n);
    }
    for(int col=j;col<n;col++){
        if(possible(b,n,i,col)){
            b[i][col]=1;
            findpossible(b,n,i+1,0);
            b[i][col]=0;
        }  
    }
}

void queen(int n){
    int **b=new int*[n];
    for(int i=0;i<n;i++){
        b[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[i][j]=0;
        }
    }
    findpossible(b,n,0,0);
    for(int i=0;i<n;i++){
        delete b[i];
    }
    delete b;
}

int main(){
    int n;
    cout<<"Enter the number of queens\n";
    cin>>n;
    queen(n);
    
}
