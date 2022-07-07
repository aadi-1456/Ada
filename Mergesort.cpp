#include<iostream>
using namespace std;

void merge(int *a,int begin,int mid,int end){
    int n1=mid-begin+1;
    int n2=end-mid;
    int l[n1],m[n2],i,j;                           // Time Complexity
    for(i=0;i<n1;i++){                             // Best case :- n*log(n)            space complexity:- n
        l[i]=a[begin+i];                           // avergade case :- n*log(n)
    }                                              // worst case :- n*log(n)
    for(j=0;j<n2;j++){
        m[j]=a[mid+1+j];
    }
    
    int k;
    i=0;
    j=0;
    k=begin;
    while(i<n1 && j<n2){
        if(l[i]<=m[j]){
            a[k]=l[i];
            i++;
        }
        else{
            a[k]=m[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = l[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = m[j];
        j++;
        k++;
    }
}

void mergesort(int *a,int begin,int end){
    if(begin<end)
    {
    int mid=(begin+end)/2;
    mergesort(a,begin,mid);
    mergesort(a,mid+1,end);
    merge(a,begin,mid,end);
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    cout<<"Enter the elements of the array\n";
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    cout<<"sorted array\n";
    for(int j=0;j<n;j++){
        cout<<a[j]<<" ";
    }
    return 0;
}
