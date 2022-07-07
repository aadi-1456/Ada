#include<iostream>
using namespace std;

void insertionsort(int *a,int n){
    int i,j,key;
    for(i=1;i<n;i++){                       //  time complexity           First Pass:12   	   11   	   13   	   5   	   6                        
        key=a[i];                           // best case :- n                       11   	   12   	   13   	   5   	   6   
        j=i-1;                              // average case :- n^2 SecP:  Third Pass:11   	   12   	   13   	   5   	   6  
        while(j>=0 && a[j]>key){            // worst case :- n^2                   11   	   12   	   5   	       13  	   6  
            a[j+1]=a[j];                    //                                     11   	   5   	       12  	       13  	   6 
            j=j-1;                          //  note                                5   	   11   	   12   	   13  	   6   
        }                                   //  best case in insertionsort is when the array is sorted.                 fourth pass:
        a[j+1]=key;
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
    insertionsort(a,n);
    cout<<"Sorted array\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
