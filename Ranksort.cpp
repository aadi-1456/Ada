#include<iostream>
using namespace std;

void ranksort(int *a,int n){   
    int r[n]={0};
    int b[n];
    for(int i=1;i<n;i++){                                       //       array
        for(int j=0;j<i;j++){          // Time complexity               15 | 12 | 16  | 25 | 10 
            if(a[j]<=a[i]){            //  best case    :- n^2           j    i
                r[i]++;                // average case  :- n^2     r[]   1 |  0 |  0  | 0  | 0
            }                          // worst case    :- n^2
            else{
                r[j]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        b[r[i]]=a[i];
    }
    for(int j=0;j<n;j++){
        a[j]=b[j];
    }
}

int main()
{
    cout<<"Enter the size of the array\n";
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ranksort(a,n);
    cout<<"sorted array elements of the array\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
