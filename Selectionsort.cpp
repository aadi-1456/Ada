#include<iostream>
using namespace std;

void selectionsort(int *a,int n){
    int i,j,min,temp;
    for(i=0;i<n-1;i++){                  //                              64, 25, 12, 22, 11
        min=i;                           //   time complexity        First pass:  64   	   25   	   12   	   22   	   11   
        j=i+1;                           //  best case    :- n^2                  11   	   25   	   12   	   22   	   64  
        while(j<n){                      //  average case :- n^2     Second Pass: 11   	   25   	   12   	   22   	   64   
            if(a[min]>a[j]){             //  worst case   :- n^2                  11   	   12   	   25   	   22   	   64   
                min=j;
            }
            j++;
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    selectionsort(a,n);
    cout<<"Sorted array\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

