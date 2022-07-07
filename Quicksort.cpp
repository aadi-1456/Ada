#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp=*b;
    *b=*a;                                       // time complexity
    *a=temp;                                     // best case :- n(log(n))
}                                                //avergae case :- \\
                                                 // worst case :- n^2
int partition(int *a,int l,int h){               // worst case is when the array is sorted in reverse order.
    int pivot=a[h];                              // best case is when the already sorted in .
    int i=(l-1);
    
    for(int j=l;j<h;j++){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[h]);
    return (i+1);
}

void quicksort(int *a,int l,int h){
    if(l<h){
        int pi=partition(a,l,h);
        quicksort(a,l,pi-1);
        quicksort(a,pi+1,h);
    }
}

int main(){
    cout<<"Enter the size of the arraay\n";
    int n;
    cin>>n;
    cout<<"Enter the elements of the array\n";
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    cout<<"Sorted array\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
