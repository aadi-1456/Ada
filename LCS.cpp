#include<iostream>
#include<algorithm>
using namespace std;

void LCS(string s1,string s2){
    int i,j;
    int m=s1.length();
    int n=s2.length();
    int lcs[m+1][n+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i==0 || j==0){
                lcs[i][j]=0;
            }
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                lcs[i][j]=lcs[i-1][j-1]+1;
            }
            else if(lcs[i-1][j]>=lcs[i][j-1]){
                lcs[i][j]=lcs[i-1][j];
            }
            else{
                lcs[i][j]=lcs[i][j-1];
            }
        }
    }
    i=m;
    j=n;
    string output;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            output += s1[i-1];
            i--;
            j--;
        }
        else if(lcs[i-1][j]>=lcs[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(begin(output), end(output));
    cout<<output;

}

int main(){
    string s1,s2;
    cout<<"Enter the first string\n";
    cin>>s1;
    cout<<"Enter the second string\n";
    cin>>s2;
    LCS(s1,s2);
    return 0;
}
